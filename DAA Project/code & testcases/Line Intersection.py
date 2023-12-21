import tkinter as tk
import time
import datetime
class LineSegment:
    def __init__(self, start, end):
        self.start = start
        self.end = end

def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    return 1 if val > 0 else 2

def on_segment(p, q, r):
    return (q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and
            q[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1]))

def do_intersect(p1, q1, p2, q2):
    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    steps = []

    steps.append(f"Orientation of {p1}, {q1}, {p2}: {o1}")
    steps.append(f"Orientation of {p1}, {q1}, {q2}: {o2}")
    steps.append(f"Orientation of {p2}, {q2}, {p1}: {o3}")
    steps.append(f"Orientation of {p2}, {q2}, {q1}: {o4}")

    if o1 != o2 and o3 != o4:
        steps.append("Line segments intersect.")
    else:
        steps.append("Line segments do not intersect.")

    if o1 == 0 and on_segment(p1, p2, q1):
        steps.append("Additional check: q1 lies on segment p1-p2.")
    if o2 == 0 and on_segment(p1, q2, q1):
        steps.append("Additional check: q1 lies on segment p1-q2.")
    if o3 == 0 and on_segment(p2, p1, q2):
        steps.append("Additional check: q2 lies on segment p2-p1.")
    if o4 == 0 and on_segment(p2, q1, q2):
        steps.append("Additional check: q2 lies on segment p2-q1.")

    return steps

class LineSegmentIntersectionApp:

    def __init__(self, root):
        self.root = root
        self.root.title("Line Segment Intersection")

        self.canvas = tk.Canvas(root, width=400, height=400)
        self.canvas.pack()

        self.segments = []
        self.canvas.bind("<Button-1>", self.on_canvas_click)

        self.status_label = tk.Label(root, text="Draw two line segments.")
        self.status_label.pack()

    def on_canvas_click(self, event):
        x, y = event.x, event.y
        self.draw_segment(x, y)

    def draw_segment(self, x, y):
        self.segments.append((x, y))

        if len(self.segments) == 4:

            # Draw the two line segments
            
            self.canvas.create_line(self.segments[0][0], self.segments[0][1],
                                    self.segments[1][0], self.segments[1][1], fill="black")
            self.canvas.create_line(self.segments[2][0], self.segments[2][1],
                                    self.segments[3][0], self.segments[3][1], fill="black")

            self.check_intersection()

    def find_intersection_point(self, p1, q1, p2, q2):
        x1, y1 = p1
        x2, y2 = q1
        x3, y3 = p2
        x4, y4 = q2

        # Calculate slopes
        slope1 = (y2 - y1) / (x2 - x1) if (x2 - x1) != 0 else float('inf')
        slope2 = (y4 - y3) / (x4 - x3) if (x4 - x3) != 0 else float('inf')

        if slope1 == slope2:
            return None  # Lines are parallel, no intersection point

        # Calculate intersection point
        x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / \
            ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4))
        y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / \
            ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4))

        return x, y

    def bounding_box_intersection(self, p1, q1, p2, q2):
        x1, y1 = p1
        x2, y2 = q1
        x3, y3 = p2
        x4, y4 = q2            
        bbox1 = (min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2))
    
        bbox2 = (min(x3, x4), min(y3, y4), max(x3, x4), max(y3, y4))

        # Check for bounding box intersection
        if bbox1[0] <= bbox2[2] and bbox1[2] >= bbox2[0] and bbox1[1] <= bbox2[3] and bbox1[3] >= bbox2[1]:
            return True  # Bounding boxes intersect

        return False  # Bounding boxes do not intersect

    def check_intersection(self):
        p1, q1 = self.segments[0], self.segments[1]
        p2, q2 = self.segments[2], self.segments[3]
        start_time = time.perf_counter()

        # Display steps for intersection check
        steps = do_intersect(p1, q1, p2, q2)
        end_time = time.perf_counter()
        print(f"Time taken to check intersection using ccw : {(end_time - start_time)} seconds")       

        start_time = time.perf_counter()
        # Check for bounding box intersection
        intersection = self.bounding_box_intersection(p1, q1, p2, q2)
        end_time = time.perf_counter()
        print(f"Time taken to check intersection using bounding box: {(end_time - start_time)} seconds")       

        start_time = time.perf_counter()
        # Find intersection point
        intersection_point = self.find_intersection_point(p1, q1, p2, q2)
        end_time = time.perf_counter()
        print(f"Time taken to find intersection: {(end_time - start_time)} seconds")       
        # Create a new window to display steps and intersection point
        self.display_steps_window(steps, intersection_point, intersection)

    def display_steps_window(self, steps, intersection_point, intersection):
        steps_window = tk.Toplevel(self.root)
        steps_window.title("Algorithm Steps")

        steps_label = tk.Label(steps_window, text="\n".join(steps))
        steps_label.pack()
        
        if intersection_point and intersection_point[0] > 0 and intersection_point[1] > 0:

            intersection_label = tk.Label(steps_window, text=f"Intersection Point using Algebra: {intersection_point}\nBounding Box: {intersection}")
            intersection_label.pack()

    def display_steps_window(self, steps, intersection_point=None, intersection=False):
            steps_window = tk.Toplevel(self.root)
            steps_window.title("Algorithm Steps")

            steps_label = tk.Label(steps_window, text="\n".join(steps))
            steps_label.pack()

            if intersection_point and intersection_point[0] > 0 and intersection_point[1] > 0:
                intersection_label = tk.Label(steps_window, text=f"Intersection Point using Algebra: {intersection_point}\nBounding Box: {intersection}")
                intersection_label.pack()

if __name__ == "__main__":
    root = tk.Tk()
    app = LineSegmentIntersectionApp(root)
    root.mainloop()
