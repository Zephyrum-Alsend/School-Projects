from Hand import Hand
from Domino import Domino
#########################################################################
#Player()                                                               #
#Members:                                                               #
#hand - Hand object.                                                    #
#Functions:                                                             #
#isPlayable(Domino, int, (int, ...)), getHand(), addDomino(Domino),     #
#removeDomino(Domino), hasWon(), reset(), reconstruct([Domino, ...])    #
#########################################################################
class Player:
    def __init__(self):
        self.__hand = Hand()

    def __str__(self):
        return str(self.__hand)

    #Checks if dom is playable based on values in playIn and pips.
    def isPlayable(self, dom, pips, passed):
        #Assumes the current player's passed value is set to True.
        for i in range(len(passed)):
            if passed[i]:
                if dom.side1() == pips[i][-1] or dom.side2() == pips[i][-1]:
                    return True

        return False

    #Player searches their hand for the engine, returns True and engine if found.
    def placeEngine(self, pip):
        for d in self.getHand():
            if d.double() and d.side1() == pip:
                self.removeDomino(d)
                return True
        return False

    #Getter.
    def getHand(self):
        return self.__hand.getHand()

    #Setter.
    def addDomino(self, dom):
        self.__hand.addDomino(dom)
    
    #Setter.
    def removeDomino(self, dom):
        self.__hand.removeDomino(dom)

    #Returns if the Player's hand is empty.
    def hasWon(self):
        return self.__hand.isEmpty()

    #Clears Hand object __hand.
    def reset(self):
        self.__hand.reset()

    #Replaces __hand's contents with newHand.
    def reconstruct(self, newHand):
        self.__hand = newHand