class QuadForm:
	def __init__(self, a, b, c):
		self.vals = dict()
		self.vals["A"] = a
		self.vals["B"] = b
		self.vals["C"] = c
	def findRoots(self):
		if (self.vals['B']**2 - 4*self.vals['A']*self.vals['C']) == 0:
			print("The root is", ((-self.vals['B'])/(2*self.vals['A'])))
		elif (self.vals['B']**2 - 4*self.vals['A']*self.vals['C']) < 0:
			print("There are no rational roots.")
		else:
			roots = ( (( (-self.vals['B']) + (self.vals['B']**2 - 4*self.vals['A']*self.vals['C'])**0.5 )/(2*self.vals['A'])), (( (-self.vals['B']) - (self.vals['B']**2 - 4*self.vals['A']*self.vals['C'])**0.5 )/(2*self.vals['A'])))
			print("The roots are", roots[0], "and", roots[1])
	def eval(self, x):
		print(self.__str__() +" = "+str(self.vals['A']*x**2 + self.vals['B']*x + self.vals['C']))
	def __str__(self):
		return str(self.vals['A'])+"x^2 + "+str(self.vals['B'])+"x + "+str(self.vals['C'])

form1, form2, form3, form4 = QuadForm(1, 5, 6), QuadForm(3, 90, 6), QuadForm(2, 4, 2), QuadForm(5, 5, 6)
form1.findRoots()
form2.findRoots()
form3.findRoots()
form4.findRoots()
form1.eval(int(input("x = ")))
print(form1)
form2.eval(int(input("x = ")))
form3.eval(int(input("x = ")))
form4.eval(int(input("x = ")))