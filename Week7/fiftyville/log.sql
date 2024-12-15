-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To see the description of the crime scene of the date you are interested in
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

--| Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today
--with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
--littering took place at 16:36. No known witnesses.


-- to see the interviews at the date
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

--| Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in
 --that time frame.


 --I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived
 --at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |--
--Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.


-- “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”                                                                                                                               |
-- “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”                                                                                                                                                                                      |
--“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.                                                                                                                   |--
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.


SELECT name FROM people JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 AND minute >= 15 AND minute <= 25 AND activity = "exit";

-- Suspects
--| Wayne   |
--|| Jordan  |
--|| Michael |
--|| Vanessa |
--|| Bruce   |
--|| Barry   |
--|| Luca    |
--|| Sofia   |
--|| Iman    |
--|| Diana   |
--|| Kelsey  |
--|| Ethan   |
--|| Vincent |
--|| Sophia  |
--|| Jeremy  |
--|| Brandon


SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND day = 28 AND month = 7 AND atm_location = "Leggett Street" AND
transaction_type = "withdraw";

-- Suspect
--| Bruce   |
--| Diana   |
--| Brooke  |
--| Kenny   |
--| Iman    |
--| Luca    |
--| Taylor  |
--| Benista

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
SELECT id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute LIMIT 1);


--| Sofia  |
--| Bruce  |
--| Edward |
--| Kelsey |
--| Taylor |
--| Kenny  |
--| Luca


SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Suspect is Bruce

SELECT city FROM airports WHERE id = (
SELECT destination_airport_id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute LIMIT 1);


-- City New York

SELECT phone_number FROM people
WHERE name = 'Bruce';

--Phone number of bruce  (367) 555-5533

SELECT name FROM people WHERE phone_number = (
SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533");


-- Accomplice Robin