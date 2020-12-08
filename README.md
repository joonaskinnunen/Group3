
# ATM Application

#### OAMK

_Joonas Kinnunen, Esa Tervonen, Tomi Uosukainen TVT20KMO_

_Tieto- ja viestintätekniikka, Ohjelmistokehityksen koulutusohjelma_

### Software Development Application Project

**Introduction:**
We created software that works like an ATM. The software differs from a normal ATM in that 
we do not use a card reader but the user enters a "card id" from the keyboard. 
Otherwise, the application resembles an ATM with the correct operation.

**Requirements:**
The ATM must work with at least three different "cards". Each card has both a debit and a credit feature. 
This must be done by creating a separate account for both properties. The debit accounts balance must not
drop below zero euros. The credit account balance must not fall below the credit limit set for the account.
When logging in to the ATM with the "card", the user must choose which account to use.

**The ATM application performs the following functions:**
 - _Withdrawal:_ 20€, 40€, 50€, 100€ and other user-entered amount
 - _Deposit:_ 20€, 40€, 50€, 100€ and other user-entered amount
 - _Account balance check_
 - _Transactions_
 - _Money transfer between accounts_ 

**Operating environment**
 - Frontend of the software is implemented using the Qt programming environment.
 - Card and account information must be stored in the MySQL database on the mysli.oamk.fi server.
 - RestApi is made on the www.students.oamk.fi server using CodeIgniter.