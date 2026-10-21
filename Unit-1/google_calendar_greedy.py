# Calendar Activity Selection using a Greedy Strategy
# This is a simplified scheduling example, not Google's actual algorithm.

events = [
    ("Study", 9, 10),
    ("Team Meeting", 9, 11),
    ("Lab", 10, 12),
    ("Project Work", 11, 12),
    ("Lunch", 12, 13),
    ("Revision", 13, 14),
]


def select_activities(activity_list):
    # Choose events that finish earliest first.
    sorted_events = sorted(activity_list, key=lambda event: event[2])
    selected = []
    last_end_time = None

    for event in sorted_events:
        name, start, end = event
        if last_end_time is None or start >= last_end_time:
            selected.append(event)
            last_end_time = end

    return selected


print("Available calendar events:")
for name, start, end in events:
    print(f"{name}: {start}:00 - {end}:00")

selected_events = select_activities(events)

print("\nSelected non-overlapping events:")
for name, start, end in selected_events:
    print(f"{name}: {start}:00 - {end}:00")

print(f"\nTotal events selected: {len(selected_events)}")
