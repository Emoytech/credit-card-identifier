# Credit Card identifier

A command-line tool that validates credit card numbers using Luhn's algorithm and identifies the issuing network (AMEX, Visa, or Mastercard).

## Features

- Validates card numbers using Luhn's algorithm
- Identifies AMEX, Visa, and Mastercard based on length and prefix
- Interactive loop — check multiple cards in one session without restarting
- Flags valid-but-unrecognized card numbers separately from invalid ones

## Download

Prebuilt Linux binary available on the [Releases page](https://github.com/Emoytech/credit-card-identifier/releases/tag/v1.0.0).

```bash
chmod +x credit-linux
./credit-linux
```

## Build from Source

Requires `gcc`.

```bash
git clone https://github.com/Emoytech/credit-card-validator.git
cd credit-card-validator
gcc -o credit credit.c
./credit
```

## Usage

```
Enter your card number: 4003600000000014
VISA
Check another card? (y/n): n
```

## How It Works

The program uses Luhn's algorithm to validate the card number: starting from the rightmost digit, every second digit is doubled, and if doubling produces a two-digit result, those two digits are summed instead. All digits are then added together — if the total is divisible by 10, the number passes the checksum.

Once a number passes the checksum, its length and leading digits are checked against known patterns to identify the card network. Numbers that pass the checksum but don't match a known pattern are reported as valid but unrecognized, rather than invalid.

## Limitations

- Only identifies AMEX, Visa, and Mastercard — other valid networks (e.g. Discover, Diners Club) are reported as "valid but not from a known list"
- No input sanitization beyond basic length/range checks

## Status
Complete / not actively maintained. Built as a learning exercise.

## License

MIT — see [LICENSE](LICENSE)
