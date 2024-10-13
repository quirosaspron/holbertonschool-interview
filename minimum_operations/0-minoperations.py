#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """ gets the fewest number of operations to get n H chars"""
    if n <= 1:
        return 0  # No operations needed if n is 1 or less

    op_counter = 0  # Total operations counter
    current_hs = 1  # Start with 1 'H'

    while current_hs < n:
        if n % current_hs == 0:
            # Copy all when current_hs divides n perfectly
            op_counter += 1  # Copy operation
            paste_size = current_hs  # Store the copied size
        # Paste the copied content
        current_hs += paste_size
        op_counter += 1  # Paste operation

    return op_counter
