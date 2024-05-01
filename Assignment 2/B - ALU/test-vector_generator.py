if __name__ == "__main__":
    with open("test_vectors.txt", "w") as file:
        file.write("A[32] B[32] ALUSel[4] Result[32]\n")
        for A in range(2**17,2**17+71,1):
            for B in range (2**16,2**16+10):
                C = A * B
                C = C//(2**32)
                if ( B > 31 | C < 0):
                    C = 0
                A_2c = format((A + 2**31) % 2**32 - 2**31, '032b')
                B_2c = format((B + 2**31) % 2**32 - 2**31, '032b')
                C_2c = format((C + 2**31) % 2**32 - 2**31, '032b')

                file.write(f"{A_2c} {B_2c} 1001 {C_2c}\n")