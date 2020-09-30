from Domino import Domino
#########################################################################
#Hand()                                                                 #
#Members:                                                               #
#hand - list containing all Dominos in the Hand                         #
#empty - flag indicating len(__hand) == 0                               #
#Functions:                                                             #
#isEmpty(), addDomino(Domino), removeDomino(Domino), getHand(),         #
#getSize(), getTally(), reset()                                         #
#########################################################################
class Hand:
    def __init__(self):
        self.__hand = []

    def __str__(self):
        l = [i for i in self.__hand]
        return ''.join(str(d) + ' ' for d in l)
    
    #Returns True if __hand is empty, false otherwise.
    def isEmpty(self):
        return len(self.__hand) == 0

    #Adds a Domino of properties dom to __hand.
    def addDomino(self, dom):
        assert isinstance(dom, Domino), "Hand can only contain Dominos."
        self.__hand.append(dom)

    #Removes a Domino of properties dom from __hand.
    def removeDomino(self, dom):
        #If dom is not a Domino, this will simply do nothing.
        self.__hand.remove(dom)

    #Returns a copy of __hand.
    def getHand(self):
        return self.__hand[:]

    #Returns the number of Dominos in __hand.
    def getSize(self):
        return len(self.__hand)

    #Returns the sum all pips in __hand.
    def getTally(self):
        sum = 0
        for d in self.__hand:
            sum += d.getTotal()
        return sum

    #Empties __hand.
    def reset(self):
        self.__hand = []

################################Test Code################################