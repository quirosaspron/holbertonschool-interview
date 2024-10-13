#!/usr/bin/python3
"""You have n locked boxes, each box may contain keys to open other boxes"""


def canUnlockAll(boxes):
    """determines if all the boxes can be opened."""
    box_state = ['closed'] * len(boxes)
    box_state[0] = 'open'
    for i, box in enumerate(boxes):
        for key in box:
            if key <= len(boxes) - 1 and key != i:
                box_state[key] = 'open'
    for state in box_state:
        if state == 'closed':
            return False
    return True
