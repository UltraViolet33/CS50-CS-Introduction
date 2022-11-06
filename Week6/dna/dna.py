import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    people = []
    csv_file = sys.argv[1]
    with open(csv_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            people.append(row)

    str = []

    with open(csv_file, newline='') as file:
        reader = csv.reader(file)
        for row in reader:
            str.append(row)


    str = str[0]
    str.pop(0)

    txt_file = sys.argv[2]
    f = open(txt_file, 'r')
    dna_sequence = f.read()

    counts_str = {}

    for item in str:
        match_count = longest_match(dna_sequence, item)
        counts_str[item] = match_count


    winner = "No match"

    for person in people:
        if match_person(person, counts_str):
            winner = person['name']

    print(winner)



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run




def match_person(person, strs):
    for str in strs:
        if int(person[str]) != strs[str]:
            return False
    return True



main()
