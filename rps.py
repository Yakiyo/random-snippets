from random import randint

moves = ('rock', 'paper', 'scissor')

def result(choice, chosen):
    if choice == 'rock' and chosen == 'scissor':
        return True
    elif choice == 'scissor' and chosen == 'paper':
        return True
    elif choice == 'paper' and chosen == 'rock':
        return True
    elif choice == 'scissor' and chosen == 'rock':
        return False
    elif choice == 'rock' and chosen == 'paper':
        return False
    elif choice == 'paper' and chosen == 'scissor':
        return False
    else:
        return 'TIE'

def game():
    chosen = moves[randint(0, len(moves) - 1)]
    choice = input('Rock, Paper, Scissor.... type your choice\n').strip().lower()
    if choice not in moves:
        print('Invalid choice. Would u like to try again or quit? (yes/no)')
        yn = input()
        if yn == 'yes':
            game()
        else:
            print('Shutting down game....')
            return
    else:
        res = result(choice=choice, chosen=chosen)
        print('Your choice: ' + choice + ', Opponent choice: ' + chosen)
        if res == True:
            print('You won!')
        elif res == False:
            print('You lost')
        elif res == 'TIE':
            print('It\'s a tie')
        print('Would you like to play again? (yes/no)')
        yn = input().strip().lower()
        if yn == 'yes':
            game()
        else:
            print('Shutting down game....')
            return
            

def start():
    print("Welcome to Rock, Paper, Scissors. Begin game? (yes/no)")
    yn = input().strip().lower()
    if yn == 'yes':
        game()
    else:
        print("Quitting process....")
        return

start()