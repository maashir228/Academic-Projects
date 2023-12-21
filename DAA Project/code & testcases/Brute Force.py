import tkinter as tk
from tkinter import filedialog, messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import sys

class ConvexHullApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Brute Force Convex Hull")

        self.points = []
        self.fig, self.ax = plt.subplots()
        self.canvas_widget = None
        self.information_text = None
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.create_widgets()

    def create_widgets(self):
        load_button = tk.Button(self.root, text="Load Points", command=self.load_points)
        load_button.pack()

        run_button = tk.Button(self.root, text="Run Brute Force", command=self.run_brute_force)
        run_button.pack()

        self.canvas_widget = FigureCanvasTkAgg(self.fig, master=self.root)
        self.canvas_widget.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        self.information_text = tk.Text(self.root, height=10, width=100)
        self.information_text.pack(side=tk.RIGHT, fill=tk.Y)

    def plot_points(self):
        #Plot the points on the canvas
        self.ax.clear()  # Clear the existing plot
        x_vals, y_vals = zip(*self.points)  # Unpack the points into x and y coordinates
        self.ax.scatter(x_vals, y_vals)  # Plot the points
        self.canvas_widget.draw()  # Refresh the canvas to display the new plot


    def load_points(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if file_path:
            self.points = self.read_points_from_file(file_path)
            self.plot_points()

    def read_points_from_file(self, filename):
        points = []
        with open(filename, 'r') as file:
            for line in file:
                parts = line.split(',')
                if len(parts) == 2:
                    x, y = parts
                    points.append((int(x), int(y)))
        return points
    
    def run_brute_force(self):
        if len(self.points) < 3:
            messagebox.showinfo("Error", "Brute Force Convex Hull requires at least 3 points.")
            return
        
        s_time = time.perf_counter()  
        self.brute_force_convex_hull(self.points)
        e_time = time.perf_counter()  
        execution_time = e_time - s_time

        Space_complexity = f"O({len(self.points)}*3)"
        Time_complexity = f"O({len(self.points)})"
        self.information_text.insert(tk.END, f"Space Complexity: {Space_complexity} for n={len(self.points)}\n")
        self.information_text.insert(tk.END, f"Time Complexity: {Time_complexity} for n={len(self.points)}\nExecution Time: {execution_time:.4f} seconds\n")

        self.canvas_widget.draw()

    
    def brute_force_convex_hull(self, points):
        hull_edges = []
        n = len(points)

        for i in range(n):
            for j in range(n):
                if i != j:
                    x1, y1 = points[i]
                    x2, y2 = points[j]

                    c = (x1 * y2) - (x2 * y1)
                    b = x1 - x2
                    a = y2 - y1

                    ytre = True

                    for g in range(n):
                        x, y = points[g]
                        equation = (a * x) + (b * y) - c

                        if equation > 0:
                            ytre = False
                            break
                        

                    if ytre:
                        hull_edges.append([(x1, y1), (x2, y2)])
                        self.display_result(hull_edges)


    def display_result(self, hull_edges):
        self.information_text.delete(1.0, tk.END)  # Clear the Text widget

        # Display all steps
        for step, edge in enumerate(hull_edges):
            step_text = f"Step {step + 1}: Edge: {edge[0]} -> {edge[1]}\n"
            self.information_text.insert(tk.END, step_text)

            # Display final convex hull image
            self.ax.clear()
            self.ax.scatter([point[0] for point in self.points], [point[1] for point in self.points], label='Points')
            self.plot_convex_hull(hull_edges)
            
            self.canvas_widget.draw() 
            self.root.update() 
            

    def plot_convex_hull(self, hull_edges):
        # Function to plot the convex hull edges
        for edge in hull_edges:
            self.ax.plot([edge[0][0], edge[1][0]], [edge[0][1], edge[1][1]], color='red', label='Convex Hull')
            time.sleep(0.25)


    def on_close(self):
        #Custom close function to properly terminate the application.
        print("Closing application")
        self.root.destroy()
        sys.exit(0)

if __name__ == "__main__":
    root = tk.Tk()
    app = ConvexHullApp(root)
    root.mainloop()
