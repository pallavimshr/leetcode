class TimeMap:

    def __init__(self):
        # Create an empty dictionary.
        # Each key will store a list of (timestamp, value) pairs.
        self.store = {}

    def set(self, key, value, timestamp):

        # If the key does not exist in dictionary,
        # create an empty list for that key.
        if key not in self.store:
            self.store[key] = []

        # Add timestamp and value as a tuple.
        # Example: [(1, "bar"), (4, "bar2")]
        self.store[key].append((timestamp, value))

    def get(self, key, timestamp):

        # If key doesn't exist, return empty string.
        if key not in self.store:
            return ""

        # Get all timestamp-value pairs for this key.
        values = self.store[key]

        # Initialize Binary Search pointers.
        low = 0
        high = len(values) - 1

        # Initially, assume no valid value is found.
        result = ""

        # Perform Binary Search.
        while low <= high:

            # Find the middle index.
            mid = (low + high) // 2

            # Get timestamp at middle index.
            time = values[mid][0]

            # If middle timestamp is less than
            # or equal to requested timestamp,
            # this value can be our answer.
            if time <= timestamp:

                # Save the corresponding value.
                result = values[mid][1]

                # Search towards the right
                # because we want a larger valid timestamp.
                low = mid + 1

            else:

                # Middle timestamp is too large.
                # Search towards the left.
                high = mid - 1

        # Return the value with the largest valid timestamp.
        # If none exists, return "".
        return result