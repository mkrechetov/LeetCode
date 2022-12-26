def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        sorted_by_right = sorted(intervals, key=lambda x: x[1])
        greedy_intervals = []
        last_right = -100000
        for interval in sorted_by_right:
            if interval[0] >= last_right:
                greedy_intervals.append(interval)
                last_right = interval[1]
        return len(intervals) - len(greedy_intervals)
