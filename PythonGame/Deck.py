from Domino import Domino
from random import shuffle
#########################################################################
#Deck(int)                                                              #
#Members:                                                               #
#trueLimit - the limit param +1, for use in for loops                   #
#remaining - number of Dominos not drawn from the Deck                  #
#top - the index of the next Domino to be drawn                         #
#empty - flag indicating if no more Dominos can be drawn                #
#boneyard - list containing all Dominos in the Deck                     #
#Functions:                                                             #
#left(), isEmpty(), draw(), reset(), reconstruct([Domino, Domino, ...]) #
#########################################################################
class Deck:
    def __init__(self, limit = 6):
        assert isinstance(limit, int), "Deck requires an integer to initialize."

        self.__trueLimit = limit + 1
        self.__top = 0
        self.__empty = False
        self.__boneyard = []

        for i in range(self.__trueLimit):
            for j in range(self.__trueLimit):
                dom = Domino(i, j)
                if dom not in self.__boneyard:
                    self.__boneyard.append(Domino(i, j))

        self.__remaining = len(self.__boneyard) - self.__top
        
        shuffle(self.__boneyard)
    
    #Print override for Deck objects. Prints all Dominos in __boneyard.
    def __str__(self):
        l = [i for i in self.__boneyard]
        return ''.join(str(d) + ' ' for d in l)

    #Returns the number of Dominos left in the Deck.
    def left(self):
        return (self.__remaining)

    #Returns the value of the __empty flag
    def isEmpty(self):
        return (self.__empty)

    #Draws a Domino from the Deck. Returns a tuple containing either:
    #False - __empty was set. No more Dominos can be drawn.
    #True, Domino - __empty not set. Domino was drawn from the deck.
    def draw(self):
        #Short circuits if __empty is set.
        if self.__empty:
            return (False,)
        
        #Draws a Domino from __boneyard and updates appropriate members.
        dom = self.__boneyard[self.__top]
        self.__top += 1
        self.__remaining -= 1
        if self.__remaining <= 0:
            self.__empty = True
        return (True, dom)

    #Reshuffles the Deck and resets members.
    def reset(self):
        shuffle(self.__boneyard)
        self.__top = 0
        self.__remaining = len(self.__boneyard)
        self.__empty = False

    #Accepts a list containing Dominos as bnyrd, and reconstructs the Deck
    #with bnyrd as a base.
    def reconstruct(self, bnyrd):
        #Assert all elements in bnyrd are of the Domino type.
        for i in bnyrd:
            assert isinstance(i, Domino), "Passed list must contain only Dominos."

        #Reconstruct the Deck. bnyrd is not empty if reconstructing a
        #pre-existing boneyard.
        self.__boneyard = bnyrd
        self.__remaining = len(bnyrd)
        self.__top = 0
        if self.__remaining == 0:
            self.__empty = True
        else:
            self.__empty = False

        #Add Dominos not found in bnyrd
        for i in range(self.__trueLimit):
            for j in range(self.__trueLimit):
                if Domino(i, j) not in bnyrd:
                    self.__boneyard.insert(0, Domino(i, j))
                    self.__top += 1 #Readjust __top.

################################Test Code################################
#Assertion testing.
#d = Deck('a')
################################
#Print testing.
#d = Deck(9)
#print(d)
################################
#draw testing.
# d = Deck()
# dom = Domino(-1, -1)
# print(d)
# t = d.draw()
# print(t)
# dom = t[1]
# print(dom)
# dom = Domino(2, 4)
# print(d)
# d = Deck(0)
# t = d.draw()
# print(t[0])
# t = d.draw()
# print(t[0])
################################
#reconstruct testing.
# d = Deck()
# d.reconstruct([])
# t = d.draw()
# print(t)
# print(d)
# d.reconstruct(['a', 'b'])