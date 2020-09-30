from Domino import Domino
from Player import Player
from Hand import Hand
#########################################################################
#Computer(int)                                                          #
#Members:                                                               #
#playerCount - the number of players in the game, so the below can wrap.#
#stackChoice - next player stack to attempt placing a Domino in.        #
#Functions:                                                             #
#takeTurn(int, (int, ...)), chooseDomino(), chooseStack(),              #
#takeDomino(Domino, int, (int, ...)), hasWon(), reset(),                #
#reconstruct([Domino, ...])                                             #
#########################################################################
class Computer(Player):
    def __init__(self, numPlayer):
        super().__init__()
        self.__playerCount = numPlayer
        self.__stackChoice = 0

    def __str__(self):
        return super().__str__()
    
    #Player chooses a Domino from their hand to play, a stack too, if it is
    #a double.
    #playIn == -1 means this Player gets to choose which stack to play in.
    #Returning -1 for stack means the Player passed.
    def takeTurn(self, playIn, pips, passed):

        print(self)

        #Determine if another stack can be played in.
        prevPassed = False
        for p in range(len(passed)):
            if p != playIn and passed[p]:
                prevPassed = True

        #Check if any Dominos in __hand can be played.
        playable = []
        for d in self.getHand():
            if super().isPlayable(d, pips, passed):
                playable.append(d)
        if not playable:
            #Pass if none are playable.
            return (-1,)

        while True:
            stack = playIn #reset stack's value.
            dom = self.chooseDomino(playable)
        
            if dom.double() or prevPassed:
                stack = self.chooseStack()

            #Check if the chosen Domino is playable in the chosen stack.
            if super().isPlayable(dom, [pips[stack]], [passed[stack]]):
                break
        
        super().removeDomino(dom)
        return (stack, dom)

    #Computer chooses the playable Domino with the highest total.
    def chooseDomino(self, playable):
        decision = [Domino(-1, -1), -2]

        for d in playable:
            if d.getTotal() > decision[1]:
                decision[0] = d
                decision[1] = d.getTotal()

        return decision[0]

    #Computer cycles through player stacks.
    def chooseStack(self):
        self.__stackChoice += 1
        self.__stackChoice %= self.__playerCount
        return (self.__stackChoice)
    
    #Player takes a Domino and attempts to play it.  Adds to __hand if unable.
    def takeDomino(self, dom, playIn, pips, passed):
        #Check if dom can be played.
        if super().isPlayable(dom, pips, passed):
            #Have Player play it.
            stack = playIn
            
            if playIn == -1 or dom.double():
                while(True):
                    stack = self.chooseStack()
                    if super().isPlayable(dom, pips, passed):
                        break

            return (True, dom, stack)
        
        #dom cannot be played, add it to __hand.
        else:
            super().addDomino(dom)
            return (False,)

    #Player searches their hand for the engine, returns True and engine if found.
    def placeEngine(self, pip):
        return super().placeEngine(pip)

    #Returns True if the Player's hand is empty.
    def hasWon(self):
        return super().hasWon()

    #Returns a copy of _Player__hand, a list of Dominos.
    def getHand(self):
        return super().getHand()

    #Resets the base class's members.
    def reset(self):
        super().reset()

    #Reconstructs the base class's hand with a new one.
    def reconstruct(self, newHand):
        super().reconstruct(newHand)

################################Test Code################################
#c = Computer(2)
#print(c)