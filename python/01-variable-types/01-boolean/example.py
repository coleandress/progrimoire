# Set our flag to False initially (no divisors found yet)

divisor_found = False

# Look for divisors of 'number' starting with 2

number = 31
i = 2

while i < number:
    if number % i == 0:
        divisor_found = True
        break

    i += 1

if divisor_found:
    print(f"Found a divisor for: {number}\n")
else:
    print(f"Looks like: {number} is a prime number\n")

print(f"The flag 'divisor_found' is: {divisor_found}\n")

# Make True into False or vice versa

divisor_found = not divisor_found

print(f"The flag 'divisor_found' is now: {divisor_found}\n")