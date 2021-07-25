# There is no char type in Python

some_character = 'Q'

print(f"some_character: {some_character}")

some_character = 'X'

print(f"some_character: {some_character}")

# The unicode value of a character can be found
# using the ord() function.  We can then convert
# back to a unicode character using the chr() function

some_character = ord(some_character)
some_character += 1
some_character = chr(some_character)

print(f"some_character: {some_character}")
