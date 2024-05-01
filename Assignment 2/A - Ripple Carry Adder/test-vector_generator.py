def adder_4bit(a, b):
    # 4-bit adder function
    carry = 0
    result = 0
    for i in range(4):
        bit_a = (a >> i) & 1
        bit_b = (b >> i) & 1

        # Calculate sum and carry
        bit_sum = bit_a ^ bit_b ^ carry
        carry = (bit_a & bit_b) | ((bit_a ^ bit_b) & carry)

        # Update result
        result |= (bit_sum << i)

    return result, carry

def generate_test_cases():
    test_cases = []
    for i in range(16):
        for j in range(16):
            a = i & 0b1111  # Ensure 4-bit inputs
            b = j & 0b1111
            sum_result, carry_out = adder_4bit(a, b)

            # Append test case as a tuple (input_a, input_b, sum_result, carry_out)
            test_cases.append((a, b, sum_result, carry_out))

    return test_cases

if __name__ == "__main__":
    test_cases = generate_test_cases()
    print("a_3 a_2 a_1 a_0 b_3 b_2 b_1 b_0 s_3 s_2 s_1 s_0 c_4")
    # Write the generated test cases to a text file
    with open("test_vectors.txt", "w") as file:
        for test_case in test_cases:
            a, b, sum_result, carry_out = test_case
            output_format = "{:01b} {:01b} {:01b} {:01b}  {:01b} {:01b} {:01b} {:01b}  {:01b} {:01b} {:01b} {:01b}  {:01b}\n"
            file.write(output_format.format((a >> 3) & 1, (a >> 2) & 1, (a >> 1) & 1, a & 1,(b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, b & 1,(sum_result >> 3) & 1, (sum_result >> 2) & 1, (sum_result >> 1) & 1, sum_result & 1,carry_out & 1))
