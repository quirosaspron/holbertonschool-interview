#!/usr/bin/env python3
import sys
from collections import defaultdict

# Initialize variables to keep track of metrics
total_size = 0
status_codes_count = defaultdict(int)  # Store counts for each status code
valid_status_codes = {"200", "301", "400", "401", "403", "404", "405", "500"}
line_count = 0

def print_metrics():
    """Print the total file size and status code counts in ascending order."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes_count):
        if status_codes_count[code] > 0:
            print(f"{code}: {status_codes_count[code]}")

try:
    for line in sys.stdin:
        parts = line.split()
        
        # Validate the input format
        if len(parts) < 7:
            continue  # Skip invalid lines

        # Extract status code and file size from the line
        status_code = parts[-2]
        file_size = parts[-1]

        # Update metrics if the status code and file size are valid
        if status_code in valid_status_codes:
            try:
                total_size += int(file_size)
                status_codes_count[status_code] += 1
            except ValueError:
                continue  # Skip lines with invalid file size

        line_count += 1

        # Print metrics after every 10 lines
        if line_count % 10 == 0:
            print_metrics()

except KeyboardInterrupt:
    # Print metrics when CTRL + C is pressed
    print_metrics()
    sys.exit(0)

# Print metrics one last time if the input ends
print_metrics()

