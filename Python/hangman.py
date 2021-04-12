def hangman(word, max_attempts):

    word = list(word)
    guessed = list(len(word) * '_')

    #max_attempts = int(input('No. of attempts you want: '))
    attempts = list(range(max_attempts))
    attempts_done = 0
    appends = 0
    for attempt in attempts:
        while attempts_done != max_attempts:
            while '_' in guessed:            
                letter = input('Enter your guessed letter: ')
                if letter in word:
                    if letter in guessed:                    
                        print('You already guessed the letter')
                    else:                   
                        guessed[word.index(letter)] = letter
                        appends += 1
                        print(f'Your guessed letter {letter} is right in {guessed}')
                    left = guessed.count('_')              
                    print(f'You have {left} letters to guess within {max_attempts - attempts_done} wrong attempts')

                else:
                    attempts_done += 1
                    left = guessed.count('_')
                    print(f'Your guess is wrong. You have {max_attempts - attempts_done} attempts left & {left} letters to guess in {guessed}') 
                    break

            else:
                print ('You won')
                break

        else:
            print('You lost')
            break
            
hangman('python', 4)
