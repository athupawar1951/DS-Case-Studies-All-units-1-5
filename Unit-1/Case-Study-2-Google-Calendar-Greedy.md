# Case Study 2: Google Calendar Application Using a Greedy Strategy

**Student Name:** ____________________  
**Branch:** Computer Engineering  
**Subject:** Data Structures  
**Unit:** 1  
**College:** ____________________

## 1. Aim
To demonstrate a Greedy strategy for selecting the maximum number of non-overlapping calendar activities.

## 2. Introduction
A calendar may contain meetings, classes, and other events. When only one event can be attended at a time, it is useful to select events that do not overlap. The activity-selection problem is a common example of the Greedy strategy.

## 3. Problem Statement
Given a list of events with start and end times, select the largest possible number of events that do not overlap.

## 4. Strategy Used: Greedy
The program sorts events by finishing time and selects the next event that starts after or when the previously selected event ends. Choosing the event that finishes earliest leaves more time for later events.

**Note:** This is a simplified activity-selection example inspired by calendar planning, not Google's actual internal calendar algorithm.

## 5. Algorithm
1. Sort all events by their end time.
2. Select the first event.
3. Check each remaining event in order.
4. Select an event if its start time is greater than or equal to the end time of the last selected event.
5. Display the selected events.

## 6. Example
Available events:

| Event | Start | End |
|---|---:|---:|
| Study | 9 | 10 |
| Team Meeting | 9 | 11 |
| Lab | 10 | 12 |
| Lunch | 12 | 13 |
| Project Work | 11 | 12 |

One valid maximum selection is Study, Lab, Project Work is not valid together because Lab ends at 12 and Project Work starts at 11. The program instead selects a maximum compatible set based on the event list and end-time order, such as Study, Project Work, Lunch if the timings allow.

## 7. Python Program
The file `google_calendar_greedy.py` contains the complete program and sample events.

## 8. How to Run
```bash
python google_calendar_greedy.py
```

## 9. Time and Space Complexity
- Sorting events: `O(n log n)`
- Selecting events after sorting: `O(n)`
- Overall time complexity: `O(n log n)`
- Space complexity: depends on the sorting implementation; the selected event list uses up to `O(n)` space.

## 10. Applications
- Planning non-overlapping meetings.
- Selecting classroom or lab sessions.
- Scheduling activities when only one can be attended at a time.

## 11. Conclusion
In this case study, I used a Greedy strategy to select non-overlapping events. Sorting by end time and choosing the next compatible event provides an efficient solution for the activity-selection problem.
