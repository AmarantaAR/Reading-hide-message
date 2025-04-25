# Reading-hide-message

C program to decode hidden messages from RGB pixel data by extracting k Least Significant Bits (LSBs) of each color component and reconstructing the original message.

---

## 📋 Description

This project demonstrates how data can be hidden within the LSBs of RGB pixel components of an image and how to retrieve that data using bitwise operations in C.

Each pixel contains 3 components: Red, Green, and Blue (8 bits each). A secret message is embedded by hiding k bits in the LSBs of each component.

The program:
- Takes the total number of pixels.
- Takes the value of `k` (number of bits hidden per component).
- Accepts the RGB component values in hexadecimal format.
- Extracts the hidden bits.
- Reconstructs and prints the hidden ASCII message.

---

## 🚀 How It Works

1. **User Input:**
   - Number of pixels in the image.
   - Number of bits hidden per RGB component (`k` where `0 < k < 8`).
   - Hexadecimal RGB values for all pixels.

2. **Bit Extraction:**
   - The program masks the k least significant bits from each RGB component.
   - These bits are sequentially assembled to form characters (8 bits per character).

3. **Message Reconstruction:**
   - Bits are accumulated into bytes.
   - Each byte is converted into an ASCII character, revealing the hidden message.

---

## 🛠️ Structure

- **main.c**: Handles user interaction, memory allocation, input reading, and initiates the decoding process.
- **rgb.c**: Contains the core functions:
  - `get_k_pixels()` – Extracts k LSBs from RGB values.
  - `decrypt_message()` – Reconstructs the message from the extracted bits.
- **rgb.h**: Header file with function declarations.

---

## 💡 Key Concepts

- **Bitwise Operations**: Efficiently manipulate and extract individual bits from bytes.
- **Dynamic Memory**: Use of `calloc()` to allocate memory based on input size.
- **Hexadecimal Input Parsing**: RGB values are entered in HEX and interpreted for bit-level processing.

---

## 📦 Compilation & Execution

### Compile:
```bash
gcc main.c rgb.c -o message
```

### Run:
```bash
./message
```

### Example

```bash
Please enter the number of pixels:
8
Please enter the number of hidden bits per component:
3
Enter 24 HEX values separated by space:
A3 10 B2 46 20 85 C4 21 13 B0 42 26 80 C5 24 11 12 20 32 46 50 65 74 81

Decoded message:
aaaaaaaaa
```