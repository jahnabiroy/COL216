module fixedLatencyMultiplier(
    input clk,
    input rst,  // Added reset input
    input [15:0] a,
    input [15:0] b,
    output reg[31:0] c_cs1221094= 0,
    output reg[0:0] completed = 0,
    output reg[31:0] clock_cycle_cs1221596 = 0
);
    reg [31:0] result = 16'b0;
    reg [4:0] i = 0;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            result <= 32'b0;
            i <= 5'b0;
            completed <= 0;
            clock_cycle_cs1221596 <= 0;
        end else begin
            clock_cycle_cs1221596 <= clock_cycle_cs1221596 + 1;
            if (i < 16) begin
                if (a[i] == 1) begin
                    result <= result + (b << i);
                end
                i <= i + 1;
            end
            if (i == 16) begin
                c_cs1221094<= result;
                completed <= 1;
                i <= 0;  // Reset i for the next multiplication
            end
        end
    end
endmodule

module tb_fixedLatencyMultiplier();
    reg [15:0] a;
    reg [15:0] b;
    wire [31:0] c_cs1221094;
    integer unsigned expected_result = 0;
    reg clk = 1;
    reg rst = 0;  // Added reset signal
    integer i = 0;
    wire completed;
    wire [31:0] clock_cycle_cs1221596;
    localparam CLK_PERIOD = 10;
    always # (CLK_PERIOD / 2) clk =~clk;
    fixedLatencyMultiplier uut(
        .clk(clk),
        .rst(rst),
        .a(a),
        .b(b),
        .c_cs1221094(c_cs1221094),
        .completed(completed),
        .clock_cycle_cs1221596(clock_cycle_cs1221596)
    );

    initial begin
        while (i < 500) begin
            // Generate test case
            a = $urandom_range(1 << 16);
            b = $urandom_range(1 << 16);

            // Assert reset to start a new multiplication
            rst = 1;
            #10;  // Hold reset for a few cycles
            rst = 0;

            // Wait for completion
//            @(posedge clk);
            while (!uut.completed) @(posedge clk);

            // Check results
            expected_result = a * b;
            $display("%d,%d,%d,%d\n", a, b, c_cs1221094, expected_result);
            if (expected_result == c_cs1221094) begin
                $display("clock cycles_cs1221596 %d", clock_cycle_cs1221596-1);
                $display("Test passed \t%d\n", i+1);
            end else begin
                $display("Test failed \t%d\n", i+1);
            end
            i = i + 1;
        end
        $finish;
    end
endmodule
