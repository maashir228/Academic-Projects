import tkinter as tk
from tkinter import filedialog, messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import time
import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def Left_index(points):
    minn = 0
    for i in range(1, len(points)):
        if points[i].x < points[minn].x:
            minn = i
        elif points[i].x == points[minn].x:
            if points[i].y > points[minn].y:
                minn = i
    return minn

def orientation(p, q, r):
    val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2

def convexHull(points, n, app):
    if n < 3:
        return

    l = Left_index(points)
    hull = []
    p = l
    q = 0
    step = 1

    while True:
        hull.append(p)
        q = (p + 1) % n

        for i in range(n):
            if orientation(points[p], points[i], points[q]) == 2:
                q = i

        p = q

        if p == l:
            break

        # Display step in the UI
        app.display_step(step, hull.copy())
        step += 1

    # Display Result in the UI
    app.display_result(hull)
    # Display the convex hull as an image
    app.display_image(hull)

class ConvexHullApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Jarvis March Convex Hull")

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
        run_button = tk.Button(self.root, text="Run Jarvis March", command=self.run_convex_hull)
        run_button.pack()

        # Canvas for plotting
        self.canvas_widget = FigureCanvasTkAgg(self.fig, master=self.root)
        self.canvas_widget.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Text widget for displaying information
        self.information_text = tk.Text(self.root, height=10, width=100)
        self.information_text.pack(side=tk.RIGHT, fill=tk.Y)
        
    def read_points_from_file(self, filename):
        points = []
        with open(filename, 'r') as file:
            for line in file:
                parts = line.split(',')
                if len(parts) == 2:
                    x, y = parts
                    points.append(Point(int(x), int(y)))
        return points

    def load_points(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if file_path:
            self.points = self.read_points_from_file(file_path)
            self.information_text.config(state=tk.NORMAL)
            self.information_text.delete('1.0', tk.END)
            self.information_text.config(state=tk.DISABLED)
            self.plot_points()  # This will clear the canvas and plot new points

            
    def run_convex_hull(self):
        if len(self.points) < 3:
            messagebox.showinfo("Error", "Jarvis March requires at least 3 points.")
            return
        # Clear previous text
        self.information_text.config(state=tk.NORMAL)
        self.information_text.delete('1.0', tk.END)

        # Run convex hull calculation
        start_time = time.perf_counter()
        convexHull(self.points, len(self.points), self)
        end_time = time.perf_counter()

        # Display execution time and complexity
        execution_time = end_time - start_time
        self.display_complexity_and_time(execution_time, len(self.points))
        self.information_text.config(state=tk.DISABLED)

    def plot_points(self):
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points], label='Points')
        self.canvas_widget.draw()

    def display_step(self, step, hull):
        
        step_text = f"Step {step}: {[str(self.points[i].x) + ', ' + str(self.points[i].y) for i in hull]}"
        self.information_text.insert(tk.END, step_text + "\n")
        
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points], label='Points')
        self.ax.plot([self.points[i].x for i in hull], [self.points[i].y for i in hull], label='Convex Hull', color='red')
        self.ax.plot([self.points[hull[-1]].x, self.points[hull[0]].x],
                     [self.points[hull[-1]].y, self.points[hull[0]].y], label='Convex Hull', color='red')

        self.canvas_widget.draw()
        time.sleep(0.1)
        self.root.update()

        if step < len(self.points):        
            result_text = f"Result: {[str(self.points[i].x) + ', ' + str(self.points[i].y) for i in hull]}"
            self.information_text.insert(tk.END, result_text + "\n")
        

    def display_complexity_and_time(self, execution_time, n):
        # Insert complexity and time information into the text widget
        self.information_text.insert(tk.END, f"Execution Time: {execution_time:.6f} seconds\n")
        self.information_text.insert(tk.END, f"Time Complexity: O({n}^2) for n={n}\n")
        self.information_text.insert(tk.END, f"Space Complexity: O({n}) for n={n}\n")
        self.information_text.config(state=tk.DISABLED)

    def display_result(self, hull):
        self.result = hull

    def display_image(self, hull):
        # Plot the points and the hull
        self.ax.clear()
        self.ax.scatter([point.x for point in self.points], [point.y for point in self.points])
        hull_points = [self.points[i] for i in hull] + [self.points[hull[0]]]
        self.ax.plot([p.x for p in hull_points], [p.y for p in hull_points], 'r-')
        self.canvas_widget.draw()

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
