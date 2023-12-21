import tkinter as tk
from tkinter import filedialog, messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from functools import cmp_to_key
import time
import sys

class Point:
    def __init__(self, x=None, y=None):
        self.x = x
        self.y = y

def nextTop(S):
    return S[-2]

def dist(p1, p2):
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))

def orien(p, q, r):
    val = ((q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y))
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2

def compare(p1, p2):
    o = orien(p0, p1, p2)
    if o == 0:
        if dist(p0, p2) >= dist(p0, p1):
            return -1
        else:
            return 1
    else:
        if o == 2:
            return -1
        else:
            return 1

class ConvexHullApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Graham Scan")

        self.points = []
        self.text_box = None
        self.fig, self.ax = plt.subplots()
        self.canvas_widget = None
        self.hull_steps = []
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.create_widgets()

    def read_points_from_file(self, filename):
        points = []
        with open(filename, 'r') as file:
            for line in file:
                parts = line.split(',')
                if len(parts) == 2:
                    x, y = parts
                    points.append(Point(int(x), int(y)))
        return points

    def create_widgets(self):
        # Load and Run buttons
        load_button = tk.Button(self.root, text="Load Points", command=self.load_points)
        load_button.pack()
        run_button = tk.Button(self.root, text="Run Graham Scan", command=self.run_convex_hull)
        run_button.pack()

        # Canvas for plotting
        self.canvas_widget = FigureCanvasTkAgg(self.fig, master=self.root)
        self.canvas_widget.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Text widget for displaying information
        self.text_box = tk.Text(self.root, height=10, width=100)
        self.text_box.pack(side=tk.RIGHT, fill=tk.Y)

    def load_points(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if file_path:
            self.points = self.read_points_from_file(file_path)
            self.plot_points()


    def display_step(self, step, hull):
        step_text = f"Step {step}: {[str(point.x) + ', ' + str(point.y) for point in hull]}"

        # Append the step to the Text widget
        self.text_box.insert(tk.END, step_text + "\n")

        
        # If all steps are displayed, plot the final convex hull
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points], label='Points')
        self.ax.plot([point.x for point in hull], [point.y for point in hull], label='Convex Hull', color='red')
        self.ax.plot([hull[-1].x, hull[0].x], [hull[-1].y, hull[0].y], label='Convex Hull', color='red')

        self.canvas_widget.draw()
        time.sleep(0.1)
        self.root.update()

    def plot_points(self):
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points], label='Points')
        self.canvas_widget.draw()

    def run_convex_hull(self):
        if len(self.points) < 3:
            messagebox.showinfo("Error", "Convex hull requires at least 3 points.")
            return

        # Time complexity calculation
        start_time = time.perf_counter() 
        self.clear_result()
        self.convexHull(self.points, len(self.points))
        end_time = time.perf_counter() 
        execution_time = end_time - start_time

        # Display the final convex hull and points
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points], label='Points')
        self.ax.plot([point.x for point in self.hull_steps[-1]], [point.y for point in self.hull_steps[-1]],
                     label='Convex Hull', color='red')
        self.ax.plot([self.hull_steps[-1][-1].x, self.hull_steps[-1][0].x],
                     [self.hull_steps[-1][-1].y, self.hull_steps[-1][0].y], label='Convex Hull', color='red')

        # Display space and time complexity in the UI along with calculation steps
        result_text = f"Result: {[str(point.x) + ', ' + str(point.y) for point in self.hull_steps[-1]]}"
        self.text_box.insert(tk.END, result_text + "\n")

        # Set the time and space complexity labels
        time_complexity = f"Time Complexity: O({len(self.points)} log {len(self.points)}) for n={len(self.points)}"
        space_complexity = f"Space Complexity: O({len(self.points)} for n={len(self.points)})"
        self.text_box.insert(tk.END, time_complexity + "\n" + space_complexity + "\n")

        # Display execution time
        execution_time_text = f"Execution Time: {execution_time:.6f} seconds"
        self.text_box.insert(tk.END, execution_time_text + "\n")

        # Draw the canvas
        self.canvas_widget.draw()

    def convexHull(self, points, n):
        global p0
        p0 = min(points, key=lambda p: (p.x, p.y))
        points = sorted(points, key=cmp_to_key(compare))

        m = 1
        for i in range(1, n):
            while i < n - 1 and orien(p0, points[i], points[i + 1]) == 0:
                i += 1
            points[m] = points[i]
            m += 1

        if m < 3:
            return

        S = []
        S.append(points[0])
        S.append(points[1])
        S.append(points[2])

        step = 1
        for i in range(3, m):
            while len(S) > 1 and orien(nextTop(S), S[-1], points[i]) != 2:
                S.pop()
            S.append(points[i])

            # Append the current convex hull to hull_steps
            self.hull_steps.append(S)

            # Display step in the UI
            self.display_step(step, S.copy())
            step += 1

        # Display Result in the UI
        self.display_result(S)

    def display_result(self, hull):
        result_text = f"Result: {[str(point.x) + ', ' + str(point.y) for point in hull]}"
        self.text_box.insert(tk.END, result_text + "\n")

    def clear_result(self):
        self.text_box.delete(1.0, tk.END)

    def on_close(self):
        #Custom close function to properly terminate the application.
        print("Closing application")
        self.root.destroy()
        sys.exit(0)

if __name__ == "__main__":
    root = tk.Tk()
    app = ConvexHullApp(root)
    root.mainloop()
