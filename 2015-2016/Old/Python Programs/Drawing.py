from ezgraphics import GraphicsWindow
import math

class shape:
	def __init__(self, color = "black", solid = "False", coord = (10, 10)):
		self.color = color
		self.solid = solid
		self.coord = coord
	def __str__(self):
		r = "A "+ self.color
		if self.solid:
			r += " solid shape"
		else:
			r += " hollow shape"
		return r

class circle(shape):
	def __init__(self, color = "red", solid = True, radius = 1):
		shape.__init__(self, color, solid)
		self.radius = radius
	def getPerimeter(self):
		return 2 * math.pi * self.radius
	def getArea(self):
		return math.pi * (self.radius**2)
	def __str__(self):
		return shape.__str__(self).replace("shape", "circle") + " with a radius of " + str(self.radius)
	def draw(self):
		if self.solid:
			canvas.setColor(self.color)
		else:
			canvas.setOutline(self.color)
			canvas.setFill()
		canvas.drawOval(self.coord[0], self.coord[1], self.radius*2, self.radius*2)

class rectangle(shape):
	def __init__(self, color = "blue", solid = False, height = 1, width = 1):
		shape.__init__(self, color, solid)
		self.height = height
		self.width = width
	def getPerimeter(self):
		return 2*self.height + 2*self.width
	def getArea(self):
		return self.height*self.width
	def __str__(self):
		return shape.__str__(self).replace("shape", "rectangle") + " with dimensions of "+str(self.height)+"x"+str(self.width)
	def draw(self):	
		if self.solid:
			canvas.setColor(self.color)
		else:
			canvas.setOutline(self.color)
			canvas.setFill()
		canvas.drawRectangle(self.coord[0], self.coord[1], self.width, self.height)

win = GraphicsWindow()
win.setTitle("Drawingz")
canvas = win.canvas()

s = shape()
print(s)
c = circle(radius = 8, color = "green")
print(c)
c.draw()
r = rectangle(width = 5, height = 10)
print(r)
r.draw()
win.wait()
print("Done!")