from random import randint


def game():
    # Generate a random number on app start
    num = randint(1, 20)
    i = int(0)
    success = bool(False)
    while i < 11:
        guess = int(input('Guess the number\n'))
        if guess != num:
            print('Wrong guess')
            i += 1
            continue
        else:
            print('You guessed the number right. Congratulations\n')
            success = bool(True)
            break
    if success == bool(True):
        print('Congrats you passed the test. Would you like to try again?\n')
    else:
        print('Ten trials have passed without you guessing the number. Would you like to continue?\n')
    yn = input('Type yes/y for continuing, no/n for quitting\n')
    if yn == 'yes' or yn == 'y':
        game()
    else:
        print('Shutting down game...')
        return 

def start():
    print('Welcome to the python number guessing game\n')
    play = input('Do you wish to begin the game? (yes/y/no/n)\n')
    if play == 'yes' or play == 'y':
        game()
    else:
        print('Shutting down game....')
        return

start()