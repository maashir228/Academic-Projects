import tkinter as tk
from tkinter import filedialog, messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import sys

class ConvexHullApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Monotone Chain Convex Hull")

        self.points = []
        self.fig, self.ax = plt.subplots()
        self.canvas_widget = None
        self.information_text = None
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.create_widgets()

    def create_widgets(self):
        # Load and Run buttons
        load_button = tk.Button(self.root, text="Load Points", command=self.load_points)
        load_button.pack()
        run_button = tk.Button(self.root, text="Run Monotone Chain", command=self.run_monotone_chain)
        run_button.pack()

        # Create a frame to hold both the canvas and the text widget
        container_frame = tk.Frame(self.root)
        container_frame.pack(fill=tk.BOTH, expand=True)

        # Create the canvas within the container frame, on the left side
        self.canvas_widget = FigureCanvasTkAgg(self.fig, master=container_frame)
        canvas_widget_frame = self.canvas_widget.get_tk_widget()
        canvas_widget_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Create the text widget within the container frame, on the right side
        self.information_text = tk.Text(container_frame, height=10, width=100)
        self.information_text.pack(side=tk.RIGHT, fill=tk.Y)


    def load_points(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if file_path:
            self.points = self.read_points_from_file(file_path)
            self.plot_points()

    def read_points_from_file(self, file_path):
        points = []
        with open(file_path, 'r') as file:
            for line in file:
                parts = line.split(',')
                if len(parts) == 2:
                    x, y = map(int, parts)
                    points.append((x, y))
        return points

    def plot_points(self):
        x_vals, y_vals = zip(*self.points)
        self.ax.clear()
        self.ax.scatter(x_vals, y_vals)
        self.canvas_widget.draw()

    def run_monotone_chain(self):
        if len(self.points) < 3:
            messagebox.showinfo("Error", "Monotone Chain requires at least 3 points.")
            return
        self.information_text.config(state=tk.NORMAL)
        self.information_text.delete('1.0', tk.END)
        start_time = time.perf_counter()
        hull = self.monotone_chain(self.points, self.information_text)
        end_time = time.perf_counter()

        execution_time = end_time - start_time
        self.plot_convex_hull(hull)
        self.display_complexity_and_time(execution_time, len(self.points))
        self.information_text.config(state=tk.DISABLED)

    @staticmethod
    def cross_product(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    def monotone_chain(self, points, text_widget):
        points = sorted(set(points))  # Remove duplicates and sort points
        if len(points) <= 1:
            return points

        # Temporary list to store lines for visualization
        temp_lines = []

        # Build lower hull
        lower = []
        for p in points:
            while len(lower) >= 2 and ConvexHullApp.cross_product(lower[-2], lower[-1], p) <= 0:
                removed_point = lower.pop()
                text_widget.insert(tk.END, f"Point {removed_point} removed from the lower hull\n")
                if len(lower) >= 1:
                    self.plot_temporary_line(lower[-1], removed_point, temp_lines)  # Visualize the line being reconsidered
            if len(lower) >= 1:
                self.plot_temporary_line(lower[-1], p, temp_lines)  # Visualize new line being added
            lower.append(p)
            text_widget.insert(tk.END, f"Point {p} added to the lower hull\n")

        # Build upper hull
        upper = []
        for p in reversed(points):
            while len(upper) >= 2 and ConvexHullApp.cross_product(upper[-2], upper[-1], p) <= 0:
                removed_point = upper.pop()
                text_widget.insert(tk.END, f"Point {removed_point} removed from the upper hull\n")
                if len(upper) >= 1:
                    self.plot_temporary_line(upper[-1], removed_point, temp_lines)  # Visualize the line being reconsidered
            if len(upper) >= 1:
                self.plot_temporary_line(upper[-1], p, temp_lines)  # Visualize new line being added
            upper.append(p)
            text_widget.insert(tk.END, f"Point {p} added to the upper hull\n")

        # Concatenate hulls excluding last point of each
        final_hull = lower[:-1] + upper[:-1]

        # Clear temporary lines and plot final hull
        self.ax.clear()
        self.plot_points()
        for p1, p2 in temp_lines:
            self.ax.plot(p1, p2, color='grey', alpha=0.5)  # Re-plot temporary lines
        self.plot_convex_hull(final_hull)  # Plot final hull

        return final_hull



    def plot_temporary_line(self, point1, point2,lines):
        # Plot a temporary line
        lines.append(((point1[0],point2[0]),(point1[1],point2[1])))
        self.ax.plot([point1[0], point2[0]], [point1[1], point2[1]], color='grey', alpha=0.5)
        self.canvas_widget.draw()
        time.sleep(0.1)  
        self.root.update()

    def display_complexity_and_time(self, execution_time, n):
        self.information_text.insert(tk.END, f"\n\nExecution Time: {execution_time:.6f} seconds\n")
        self.information_text.insert(tk.END, f"Time Complexity: O({n} log {n}) for n={n}\n")
        self.information_text.insert(tk.END, f"Space Complexity: O({n}) for n={n}\n")
        self.information_text.config(state=tk.DISABLED)

    def plot_convex_hull(self, hull):
        self.ax.clear()
        self.plot_points()
        if hull:
            x_vals, y_vals = zip(*hull)
            self.ax.plot(x_vals + (x_vals[0],), y_vals + (y_vals[0],), 'r-')  # Loop back to the first point
        self.canvas_widget.draw()


    def on_close(self):
        #Custom close function to properly terminate the application.
        print("Closing application")
        self.root.destroy()
        sys.exit(0)

if __name__ == "__main__":
    root = tk.Tk()
    app = ConvexHullApp(root)
    root.mainloop()
