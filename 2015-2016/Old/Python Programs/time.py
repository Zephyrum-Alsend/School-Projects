

class Time :

    #------------------ Your Code should be contained within this class------
    #
    # No code should be added outside the class
    #------------------------------------------------------------------------


# You may comment out an assertion to skip it if it is failing.




t1 = Time(5, 30)
assert t1.hours == 5, "Assertion 1 Failed"  # 10 points
assert t1.minutes == 30, "Assertion 2 Failed"    # 10 points

t2 = Time(5, 90)
assert t2.hours == 6, "Assertion 3 Failed"  # 5 Points - minutes > 60 should wrap hour
assert t2.minutes == 30, "Assertion 4 Failed" # 5 Points - minutes modified if > 60

t1.addHours(12)
assert t1.hours == 17, "Assertion 4 Failed" # 5 Points - hours should be added correctly
t1.addHours(7)
assert t1.hours == 0, "Assertion 5 Failed" # 5 Points - If hours is over 23, need to wrap around to 0

t2.addMinutes(40)
assert t2.minutes == 10, "Assertion 6 Failed" # 5 Points - Minutes should wrap when over 60

t2.addHours(7)
assert str(t2) == "2:10pm", "Assertion 7 Failed" # 5 Points - Timestamp should reflect am/pm and print in 12/hour format

t2.addHours(-7)
assert str(t2) == "7:10am", "Assertion 8 Failed" # 5 Points - Timestamp should reflect am/pm and print in 12/hour format

assert str(t1) == "12:30am", "Assertion 9 Failed" # 5 Points - Timestamp deals with midnight correctly

