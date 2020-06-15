word = list('nilesh')
guessed = list('_____')

max_attempts = int(input('No. of attempts you want: '))
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
                print(f'You have {len(word) - appends} letters to guess.')
        
            else:
                attempts_done += 1
                print(f'Your guess is wrong. You have {max_attempts - attempts_done} attempts left & {len(word) - appends} letters to guess') 
                break
        
        else:
            print ('You won')
            break

    else:
        print('You lost')
        break