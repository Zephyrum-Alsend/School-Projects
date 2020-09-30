from Human import Human
from Computer import Computer
from Domino import Domino
from Deck import Deck
#########################################################################
#Board(int, int, int)                                                   #
#Members:                                                               #
#deck - contains a Deck object, initialized with deckSize.              #
#engineStart - the initial and highest possible engine value.           #
#players - list containing Human and Computer objects.                  #
#largeGame - boolean indicating if there are more than 2 players.       #
#passed - list of booleans indicating who passed their turn.            #
#stacks - list of list of Dominos played by each player.                #
#playNext - list of list of ints indicating what Dominos can be played. #
#currentTurn - index determining which player's turn it currently is.   #
#engine - int containing the current engine value.                      #
#engineSet - boolean indicating if the engine has been placed.          #
#Functions:                                                             #
#largeBoardDisplay(), smallBoardDisplay(), executeTurn(), findEngine(), #
#computeScore(), incrementTurn(), updatePlayNext(int, Domino),          #
#newRound(), reset(), drawHands(), checkEndCondition(),                 # 
#reconstruct(self, int, [Boolean, [Domino, ...]],                       #
#            [[Domino, ...], [Domino, ...]], [Domino, ...], int, int)   #
#########################################################################
class Board:
    def __init__(self, playerCount = 2, deckSize = 6, comp = 1):
        self.__deck = Deck(deckSize)
        self.__engineStart = deckSize
        
        self.__players = []
        for i in range(comp):
            self.__players.append(Computer(playerCount))
        for i in range(playerCount - comp):
            self.__players.append(Human())

        if playerCount > 2:
            self.__largeGame = True
        else:
            self.__largeGame = False

        self.__passed = [False for i in range(playerCount)]
        self.__stacks = [[] for i in range(playerCount)]
        self.__playNext = [[self.__engineStart] for i in range(playerCount)]
        self.__currentTurn = 0
        self.__engine = self.__engineStart
        self.__engineSet = False

        self.__passMessage = 'Passed.'
    
    def __str__(self):
        if self.__largeGame:
            return self.largeBoardDisplay() + 'P' + str(self.__currentTurn + 1) + ':'
        else:
            return self.smallBoardDisplay() + 'P' + str(self.__currentTurn + 1) + ':'

    #When there are 3 - 4 players, display stack crosswise.  Doubles are not
    #displayed vertically.
    def largeBoardDisplay(self):
        lineP1, lineP2, lineP3, lineP4 = ('' for i in range(4))
        
        #Generate P1's stack.
        lineP1 += 'P1 '
        #__playNext sub-lists have 1 more element than __stacks sub-lists.
        #Find which side should be on the right.
        for i, d in reversed(list(enumerate(self.__stacks[0]))):
            if d.side2() == self.__playNext[0][i]:
                lineP1 += str(d)
            else:
                lineP1 += str(d)[::-1]

        #Offset for P3's and P4's stacks.
        offset = len(lineP1)

        #Add the engine to P2's stack.
        lineP2 += str(self.__engine) + '-' + str(self.__engine)

        #Generate P2's stack.
        for i, d in list(enumerate(self.__stacks[1])):
            #__playNext sub-lists have 1 more element than __stacks sub-lists.
            #Find which side should be on the left.
            if d.side1() == self.__playNext[1][i]:
                lineP2 += str(d)
            else:
                lineP2 += str(d)[::-1]

        lineP2 += ' P2\n'

        #Generate P3's stack.
        lineP3 += (' ' * offset) + 'P3\n'
        for d in self.__stacks[2]:
            lineP3 += (' ' * offset) + str(d) + '\n'

        #Generate P4's stack, if it exists.
        if len(self.__players) >= 4:
            for d in self.__stacks[3][::-1]:
                lineP4 += (' ' * offset) + str(d) + '\n'
            lineP4 += (' ' * offset) + 'P4\n'

        return lineP3 + lineP1 + lineP2 + lineP4

    #For a game of 2 players, displays stacks in a line with the engine in the
    #middle.  Doubles (including the engine) are displayed vertically.
    def smallBoardDisplay(self):
        line1, line2, line3 = ('' for i in range(3))

        #Put together P1's stack.
        line1 += '   '
        line2 += 'P1 '
        line3 += '   '
        for i, d in reversed(list(enumerate(self.__stacks[0]))):
            if d.double():
                line1 += str(d.side1())
                line2 += '|'
                line3 += str(d.side2())
            #__playNext sub-lists have 1 more element than __stacks sub-lists.
            #Find which side should be on the right.
            elif d.side2() == self.__playNext[0][i]:
                line1 += '   '
                line2 += str(d)
                line3 += '   '
            else:
                line1 += '   '
                line2 += str(d)[::-1]
                line3 += '   '

        #Add the engine.
        line1 += str(self.__engine)
        line2 += '|'
        line3 += str(self.__engine)

        #Put together P2's stack.
        for i, d in list(enumerate(self.__stacks[1])):
            if d.double():
                line1 += str(d.side1())
                line2 += '|'
                line3 += str(d.side2())
            #__playNext sub-lists have 1 more element than __stacks sub-lists.
            #Find which side should be on the left.
            elif d.side1() == self.__playNext[1][i]:
                line1 += '   '
                line2 += str(d)
                line3 += '   '
            else:
                line1 += '   '
                line2 += str(d)[::-1]
                line3 += '   '
        line1 += '   '
        line2 += ' P2'
        line3 += '   '

        return line1 + '\n' + line2 + '\n' + line3 + '\n'

    #Has the current player take their turn.  If they pass, the player draws a
    #Domino and may play it if they can.
    #Returns True if a player won, False otherwise.
    def executeTurn(self):
        #Declare this first so isPlayable inside takeTurn will work properly.
        self.__passed[self.__currentTurn] = True

        temp1 = self.__players[self.__currentTurn].takeTurn(self.__currentTurn, self.__playNext[:], self.__passed[:])
        
        #If the player had to pass...
        if temp1[0] == -1:
            #Draw a Domino...
            temp2 = self.__deck.draw()
            
            #If a Domino could be drawn...
            if temp2[0]:
                #Have the player attempt to play the drawn Domino.
                temp3 = self.__players[self.__currentTurn].takeDomino(temp2[1], self.__currentTurn, self.__playNext[:], self.__passed[:])
                
                #If the player successfully played the drawn Domino...
                if temp3[0]:
                    #Place the Domino in the appropriate stack.
                    #[2] contains a stack index; [1] contains a Domino.
                    self.__stacks[temp3[2]].append(temp3[1])
                    self.__passed[self.__currentTurn] = False
                    self.updatePlayNext(temp3[2], temp3[1])
       
        #The player has a Domino to play.
        else:
            #[2] contains a stack index; [1] contains a Domino.
            
            self.__stacks[temp1[0]].append(temp1[1])
            self.__passed[self.__currentTurn] = False
            self.updatePlayNext(temp1[0], temp1[1])
        
        #If the player truly passed, __passed is already appropriately set.
        if self.__passed[self.__currentTurn]:
            print(self.__passMessage)
        
        ret = self.__players[self.__currentTurn].hasWon()
        self.incrementTurn()
        return (ret)
    
    #Has the current player search their hand for the engine.  If not found,
    #the player draws a Domino.
    #Returns two booleans indicating 1) if the engine was found/placed and
    #2) if the deck is empty.
    def findEngine(self):
        self.__passed[self.__currentTurn] = True
        if self.__players[self.__currentTurn].placeEngine(self.__engine):
            #The engine was found within the player's hand.
            self.__engineSet = True
            self.__passed[self.__currentTurn] = False

        else:
            #Draw a Domino.
            resultTuple = self.__deck.draw()

            #If __deck was not empty...
            if resultTuple[0]:
                dom = resultTuple[1]

                #If dom might be the engine...
                if dom.double():
                    resultTuple = self.__players[self.__currentTurn].takeDomino(dom, -1, self.__playNext[:], self.__passed[:])
                    
                    if resultTuple[0]:
                        self.__engineSet = True
                        self.__passed[self.__currentTurn] = False
                
                #dom cannot be the engine
                else:
                    #Call takeDomino with an impossible to satisfy condition.
                    resultTuple = self.__players[self.__currentTurn].takeDomino(dom, -1, [-1], [False])

        self.incrementTurn()
        return (self.__engineSet, self.__deck.isEmpty())

    #Has every one in __players draw 8 Dominos from the __deck.
    #Returns False if __deck is empty, True otherwise.
    def drawHands(self):
        for p in self.__players:
            for i in range(8):
                resultTuple = self.__deck.draw()

                if resultTuple[0]:
                    dom = resultTuple[1]
                    #Call takeDomino with an impossible to satisfy condition.
                    resultTuple = p.takeDomino(dom, -1, [-1], [False])
                else:
                    return False
                
        return True

    #Returns True if the game cannot continue, False otherwise.
    def checkEndCondition(self):
        #If the deck is empty...
        if not self.__deck.isEmpty():
            return False

        #If all players have passed...
        for p in self.__passed:
            if not p:
                return False

        #Game cannot continue.
        return True

    #Tallies the pips in each players hand as their score and returns the score
    #of every player in a list.
    def computeScore(self):
        scores = []
        for p in range(len(self.__players)):
            scores.append(sum([d.getTotal() for d in self.__players[p].getHand()]))
        return scores[:]

    #move this to round
    def findWinner(self, scores):
        return scores.index(max(scores))

    #Increments the turn counter and wraps as necessary.
    def incrementTurn(self):
        self.__currentTurn += 1
        self.__currentTurn %= len(self.__players)

    #Updates playNext sub-list for player playIn.
    def updatePlayNext(self, playIn, dom):
        #Since pips need to match, playNext will become the other side.
        if dom.side1() == self.__playNext[playIn][-1]:
            self.__playNext[playIn].append(dom.side2())
        else:
            self.__playNext[playIn].append(dom.side1())

    #Prepares the board for a new round, resetting members and decrementing the
    #__engine.
    def newRound(self):
        self.__deck.reset()
        
        for p in self.__players:
            p.reset()

        self.__stacks = [[] for i in range(len(self.__players))]
        self.__currentTurn = 0
        self.__engine -= 1
        self.__engine %= self.__engineStart
        self.__engineSet = False
        self.__playNext = [[self.__engine] for i in range(len(self.__players))]
        self.__passed = [False for i in range(len(self.__players))]
    
    #Resets all members of Board.
    def reset(self):
        self.__deck.reset()
        
        for p in self.__players:
            p.reset()

        self.__stacks = [[] for i in range(len(self.__players))]
        self.__currentTurn = 0
        self.__engine = self.__engineStart
        self.__engineSet = False
        self.__playNext = [[self.__engine] for i in range(len(self.__players))]
        self.__passed = [False for i in range(len(self.__players))]

    #Resets __passed to all False. Used after engine is played.
    def resetPass(self):
        self.__passed = [False for i in range(len(self.__players))]

    def reconstruct(self, engn, plyrs, stcks, bnyrd, numPassed, nextTurn):
        pass

################################Test Code################################
#b = Board(3)
#print(b)
#print(b.computeScore())
