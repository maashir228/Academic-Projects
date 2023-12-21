import tkinter as tk
from tkinter import filedialog, messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import sys

class ConvexHullApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Quick Elimination Convex Hull")

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
        run_button = tk.Button(self.root, text="Run Quick Elimination", command=self.run_quick_elimination)
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

    def run_quick_elimination(self):
        if len(self.points) < 3:
            messagebox.showinfo("Error", "Quick Elimination requires at least 3 points.")
            return
        
        # Clear previous text
        self.information_text.config(state=tk.NORMAL)
        self.information_text.delete('1.0', tk.END)
        
        # Run the algorithm and display results
        start_time = time.perf_counter()
        lines = []
        hull=self.quickhull(self.points, self.information_text,lines)
        end_time = time.perf_counter()
        self.plot_convex_hull(hull)
        # Display execution time and other information
        execution_time = end_time - start_time
        self.display_complexity_and_time(execution_time, len(self.points))

        # Draw the convex hull
        
        self.information_text.config(state=tk.DISABLED)

    @staticmethod
    def distance(point, line_points):
        # Calculate the distance from point to the line defined by line_points (P, Q)
        P, Q = line_points
        num = abs((Q[1] - P[1])*point[0] - (Q[0] - P[0])*point[1] + Q[0]*P[1] - Q[1]*P[0])
        den = ((Q[1] - P[1])**2 + (Q[0] - P[0])**2)**0.5
        return num / den

    def quickhull(self, S, text_widget,lines):
        def find_hull(Sk, P, Q, side, text_widget):
            if not Sk:
                return []
            farthest_point = max(Sk, key=lambda point: ConvexHullApp.distance(point, (P, Q)))

            for point in Sk:
                if point != farthest_point:
                    self.plot_temporary_line(P,point,lines)
                    self.plot_temporary_line(point, Q,lines)
                    
            # Plot each line being considered temporarily
            self.plot_temporary_line(P, farthest_point,lines)  # Plot the line from P to farthest_point
            self.plot_temporary_line(farthest_point, Q,lines)  # Plot the line from farthest_point to Q

            # Update the text widget with the newly added point to the convex hull
            text_widget.insert(tk.END, f"Point {farthest_point} is added to the convex hull on the {side} side of the line from {P} to {Q}\n")
            text_widget.see(tk.END)

            # Points to the right of line PQ
            S1 = [point for point in Sk if (farthest_point[1] - P[1]) * (point[0] - P[0]) > (farthest_point[0] - P[0]) * (point[1] - P[1])]
            # Points to the right of line QC
            S2 = [point for point in Sk if (Q[1] - farthest_point[1]) * (point[0] - farthest_point[0]) > (Q[0] - farthest_point[0]) * (point[1] - farthest_point[1])]

            Convex_Hull.insert(Convex_Hull.index(Q), farthest_point)

            # Recursive calls for each subset
            find_hull(S1, P, farthest_point, "left", text_widget)
            find_hull(S2, farthest_point, Q, "right", text_widget)

        # Start with the leftmost and rightmost points, A and B
        A = min(S, key=lambda point: point[0])
        B = max(S, key=lambda point: point[0])
        Convex_Hull = [A, B]

        # Update the text widget with the initial points of the convex hull
        text_widget.insert(tk.END, f"Starting points of the convex hull: {A}, {B}\n")
        text_widget.see(tk.END)

        # Split the set into two subsets, one on each side of the line AB
        left_of_line = [point for point in S if (B[1] - A[1]) * (point[0] - A[0]) > (B[0] - A[0]) * (point[1] - A[1])]
        right_of_line = [point for point in S if (A[1] - B[1]) * (point[0] - B[0]) > (A[0] - B[0]) * (point[1] - B[1])]

        # Build convex hull for each subset
        find_hull(left_of_line, A, B, "left", text_widget)
        find_hull(right_of_line, B, A, "right", text_widget)
            
        return Convex_Hull

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
        # This function is called at the end to plot the final convex hull
        self.ax.clear()
        self.plot_points()
        if hull:
            x_vals, y_vals = zip(*hull)
            self.ax.plot(x_vals + (x_vals[0],), y_vals + (y_vals[0],), 'r-')  # Plot final convex hull
        self.canvas_widget.draw()

    def on_close(self):
        # Custom close function to properly terminate the application.
        print("Closing application")
        self.root.destroy()
        sys.exit(0)

if __name__ == "__main__":
    root = tk.Tk()
    app = ConvexHullApp(root)
    root.mainloop()