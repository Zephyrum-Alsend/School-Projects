def quadratic(co):
	descrim = (co[1]**2) - (4*co[0]*co[2])
	if descrim < 0:
		return None
	else:
		roots = ( ((-co[1]) + decrim**0.5) / (2*co[0]), ((-co[1]) - descrim**0.5) / (2*co[0]) )
		return roots

def findrealroots(co):
	if quadratic(co) == None:
		print("There are no real roots.")
	else:
		root1, root2 = quadratic(co)
		if root1 != root2:
			print(root1, root2)
		else:
			print(root1)

e = (int(input("A = ")), int(input("B = ")), int(input("C = ")))
findrealroots(e)