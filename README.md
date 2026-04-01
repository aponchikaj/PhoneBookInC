# 📒 Phone Book in C
**By Lazare Mirziashvili**

A terminal-based contact management application written in C. Supports adding, deleting, updating, and looking up contacts — all from an interactive menu.

---

## Features

- **Add Contact** — Save a name, phone number, and country code
- **Delete Contact** — Remove a contact by its index
- **Update Contact** — Edit an existing contact's name, phone, or country code
- **View All Contacts** — List every saved contact
- **Find by Index** — Look up a single contact by its index number
- Duplicate phone number detection
- Up to **100 contacts** stored in memory

---

## Getting Started

### Requirements

- A C compiler: `gcc` or `clang`
- Any UNIX-like terminal (Linux, macOS) or Windows with MinGW/WSL

### Build & Run

```bash
gcc -o phonebook phonebook.c
./phonebook
```

---

## Usage

When you launch the program, you'll see an interactive menu:

```
MENU:
1. Add Contact
2. Delete Contact
3. Update Contact
4. Get Contacts
5. Get Contact
6. Exit

 Choose:
```

Enter the number of the action you want and follow the prompts.

### Example Session

```
Choose: 1

Enter Contact's name: Lazare
Enter Contact's phone: 555123456
Enter Contact's country code: +995

Added successfully!

Choose: 4

 #0 | Lazare | +995 | 555123456
```

---

## Project Structure

```
phonebook.c        # All source code (single-file project)
README.md          # This file
```

### Key internals

| Symbol | Role |
|---|---|
| `contact` | Struct holding name, phone, country code, index |
| `CONTACTS[100]` | Static array of all contacts |
| `CONTACTS_SIZE` | Current number of saved contacts |
| `StringLength()` | Custom string length (no `strlen`) |
| `compareStrings()` | Custom string equality check |

---

## Known Limitations

- Contacts are stored **in memory only** — everything is lost when the program exits (no file persistence)
- Names and phone numbers **cannot contain spaces** (uses `scanf %s`)
- Maximum of **100 contacts**

---

## License

Free to use and modify for educational purposes.