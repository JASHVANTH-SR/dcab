#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int opcode;
    int op1;
    int op2;
    int result;
} Instruction;

void generate_code(Instruction* instructions, int num_instructions) {
    // Code generation phase
    // Translate intermediate code into machine code
    for (int i = 0; i < num_instructions; i++) {
        Instruction instr = instructions[i];
        switch (instr.opcode) {
            case 1: // Add
                printf("ADD R%d, R%d, R%d\n", instr.result, instr.op1, instr.op2);
                break;
            case 2: // Subtract
                printf("SUB R%d, R%d, R%d\n", instr.result, instr.op1, instr.op2);
                break;
            case 3: // Multiply
                printf("MUL R%d, R%d, R%d\n", instr.result, instr.op1, instr.op2);
                break;
            case 4: // Divide
                printf("DIV R%d, R%d, R%d\n", instr.result, instr.op1, instr.op2);
                break;
            case 5: // Move
                printf("MOV R%d, %d\n", instr.result, instr.op1);
                break;
            case 6: // Load
                printf("LOAD R%d, %d(R%d)\n", instr.result, instr.op2, instr.op1);
                break;
            case 7: // Store
                printf("STORE R%d, %d(R%d)\n", instr.op1, instr.op2, instr.result);
                break;
            default:
                printf("Invalid opcode\n");
                exit(1);
        }
    }

    // Optimization phase
    // Apply optimizations to the generated machine code
    // (not implemented in this example)
}

int main() {
    Instruction instructions[7] = {
        {1, 2, 3, 1}, // Add R1, R2, R3
        {2, 4, 5, 2}, // Sub R2, R4, R5
        {3, 6, 7, 3}, // Mul R3, R6, R7
        {4, 8, 9, 4}, // Div R4, R8, R9
        {5, 10, 0, 5}, // Mov R5, 10
        {6, 11, 12, 6}, // Load R6, 12(R11)
        {7, 13, 14, 0}  // Store R13, 14(R0)
    };

    generate_code(instructions, 7);

    return 0;
}
