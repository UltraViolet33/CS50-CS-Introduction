import cs50 as cs


def main():
    text = cs.get_string("Text : ")

    letters = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    grade = calculate_grade(letters, sentences, words)

    if grade < 1:
        print("Before Grade 1\n")
    elif grade > 16:
        print("Grade 16+\n")
    else:
        print(f"Grade {grade}\n")


def count_letters(text):
    number_letters = 0

    for i in range(len(text)):
        if text[i].isalpha():
            number_letters += 1

    return number_letters


def count_words(text):

    number_words = 0

    for i in range(len(text)):
        if text[i].isspace():
            number_words += 1

    return number_words + 1


def count_sentences(text):
    sentences = 0

    count_period = count_char(text, ".")
    count_interro = count_char(text, "?")
    count_excla = count_char(text, "!")

    sentences = count_interro + count_period + count_excla

    return sentences


def count_char(str, c):
    count = 0

    for i in range(len(str)):
        if str[i] == c:
            count += 1

    return count


def calculate_grade(letters, sentences, words):
    L = 100.000 * letters / words
    S = 100.000 * sentences / words

    f = 0.0588 * L - 0.296 * S - 15.8
    return int(round(f))


main()
