# Strings can be copied with the assignment operator

some_string = ""

some_other_string = "another string entirely"

some_string = some_other_string

some_other_string = "I changed"

print(f"some_string: {some_string}")
print(f"some_other_string: {some_other_string}")

# Other options available are the slice syntax
# some_string = some_other_string[:]

# ..or the str() function
# some_string = str(some_other_string)