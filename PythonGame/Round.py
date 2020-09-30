from Board import Board
#########################################################################
#Round(int, int, int)                                                   #
#Members:                                                               #
#board - Board object initialized using all parameters.                 #
#score - list of integers containing each player's end of round score.  #
#winner - index indicating which player won the round.                  #
#Functions:                                                             #
#runRound(), roundEnd(), getScores(), findWinner([int, ...]), reset(),  #
#reconstruct()                                                          #
#########################################################################
class Round:
    def __init__(self, playerCount = 2, deckSize = 6, comp = 1):
        self.__board = Board(playerCount, deckSize, comp)
        self.__score = []
        self.__winner = 0

    def __str__(self):
        ret = '\nRound Scores:\n'

        for s in range(len(self.__score)):
            ret += 'P' + str(s) + ': ' + str(self.__score[s]) + '\n'
            
        return ret

    #Executes a round of the game.
    #Returns False if the game ended prematurely.
    def runRound(self):
        #Have all players draw their hands.
        if not self.__board.drawHands():
            #Not enough Dominos for all players.
            return False

        #Look for the engine.
        while True:
            resultTuple = self.__board.findEngine()
            #[0] indicates if the engine was found;
            if resultTuple[0]:
                break
            #[1] indicates if the deck is empty.
            elif resultTuple[1]:
                #Check for the end condition.
                if self.__board.checkEndCondition():
                    #No one found the engine anywhere.
                    return False

        #Reset __passed flags in __board.
        self.__board.resetPass()

        #Run the game until an end condition is met.
        while True:
            print(self.__board)
            if self.__board.executeTurn() or self.__board.checkEndCondition():
                break

        return True

    #Gathers the scores of all players and determines a winner.  Sets up board
    #for next round.
    #Returns (int, [int, ...]) containing the winner's index and list of scores
    #respectively.
    def roundEnd(self):
        self.__score = self.getScores()
        self.__winner = self.findWinner(self.__score)
        self.__board.newRound()
        return (self.__winner, self.__score)

    #Prompts __board for the scores of each player.
    def getScores(self):
        return self.__board.computeScore()

    #Determines which player won the round.
    def findWinner(self, scores):
        return scores.index(max(scores))

    #Resets all members.
    def reset(self):
        self.__board.reset()
        self.__score = []
        self.__winner = 0

    #Reconstructs the round from given information.
    def reconstruct(self):
        pass

################################Test Code################################
r = Round()
r.runRound()
r.roundEnd()
print(r)