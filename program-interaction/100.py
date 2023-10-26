import subprocess
import re

# Run the challenge program and interact with it
with subprocess.Popen(["/challenge/embryoio_level100"], 
                      stdin=subprocess.PIPE, 
                      stdout=subprocess.PIPE, 
                      stderr=subprocess.PIPE, 
                      text=True) as proc:
    while True:

        # Read output until we find the arithmetic problem
        while True:
            line = proc.stdout.readline()
            print(line, end='')  # Print the line to stdout
            if "[TEST] CHALLENGE!" in line:
                break
            if "pwn" in line:
                break 
        if "pwn" in line:
            break
        
        # Extract the problem from the output line
        match = re.search(r'Please send the solution for: (.*)', line)
        if match:
            problem = eval(match.group(1))
            
            # Solve the arithmetic problem (assuming it's just to echo back the number)
            solution = problem  # Modify this as needed to solve the actual problem
            print(solution)
            # Send the solution back to the program's stdin
            proc.stdin.write(f"{solution}\n")
            proc.stdin.flush()
            
    # Read the remaining output
    output = proc.communicate()[0]
    print(output)
