#########################################################
#Domino(int, int)                                       #
#Members:                                               #
#val1 - number of pips on the first half of the Domino  #
#val2 - number of pips on the second half of the Domino #
#isDouble - indicates if val1 == val2                   #
#total - contains the sum of val1 and val2              #
#Functions:                                             #
#side1(), side2(), double(), getTotal()                 #
#########################################################
class Domino:
    def __init__(self, pip1 = 0, pip2 = 0):
        #Assert pip1 and pip2 are integers to ensure proper usage.
        assert isinstance(pip1, int) and isinstance(pip2, int), "Domino requires two integers to initialize."

        #Halves are ordered lesser value first.
        if pip1 < pip2:
            self.__val1 = pip1
            self.__val2 = pip2
        else:
            self.__val1 = pip2
            self.__val2 = pip1
        
        #Sets the isDouble flag as appropriate.
        if pip1 == pip2:
            self.__isDouble = True
        else:
            self.__isDouble = False
        
        #Calculates and stores the total.
        self.__total = pip1 + pip2
    
    #Print override for Domino objects.
    def __str__(self):
        return "%s-%s" % (self.__val1, self.__val2)

    def __eq__(self, other):
        return self.__val1 == other.side1() and self.__val2 == other.side2()

    #Returns the number of pips on the first half of the Domino.
    def side1(self):
        return (self.__val1)

    #Returns the number of pips on the second half of the Domino.
    def side2(self):
        return (self.__val2)

    #Returns True if there are the same number of pips on each half.
    def double(self):
        return (self.__isDouble)

    #Returns the total number of pips on the entire Domino.
    def getTotal(self):
        return (self.__total)

################################Test Code################################
#Assertion testing.
#d = Domino('a', 'b')
################################
#Function testing.
#d = Domino(1, 2)
#print(d.side1())
#print(d.side2())
#print(d.double())
#print(d.getTotal())
#
#d = Domino(2, 1)
#print(d.side1())
#print(d.side2())
#print(d.double())
#print(d.getTotal())
#
#d = Domino(0, 0)
#print(d.double())
################################
#Encapsulation testing.
#d = Domino(1, 2)
#b = d.side1()
#b = 42
#print(d.side1())
#d.__val1 = 42
#print(d.side1())
################################
#Output testing.
#d = Domino(1,2)
#print(d)
################################
# d1 = Domino(2, 2)
# d2 = Domino(2, 2)
# d3 = Domino(2, 3)
# print(d1 == d2)
# print(d1 == d3)
# print(d2 == d3)