import cs50 as cs


def main():
    cents = 0
    while cents <= 0:
        cents = cs.get_float("Change owed : ")

    quarters = calculate(cents, 0.25)
    cents = cents - quarters * 0.25

    dimes = calculate(cents, 0.10)
    cents -= dimes * 0.10
    cents = round(cents, 2)

    nickels = calculate(cents, 0.05)
    cents -= nickels * 0.05
    cents = round(cents, 2)

    pennies = calculate(cents, 0.01)
    cents -= pennies
    sum_coins = quarters + dimes + nickels + pennies

    return sum_coins


def calculate(cents, coins):
    count = 0
    while cents >= coins:
        if cents == 0:
            break
        cents -= coins
        count += 1

    return count


sum_coins = main()


print(sum_coins)
print("\n")
