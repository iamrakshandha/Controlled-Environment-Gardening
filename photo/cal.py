import pandas

df = pandas.read_csv('photo.csv', header=None)
lengthOfDf = len(df.columns)
lastRowValue = df.tail(1)[lengthOfDf - 1]
upTime = lastRowValue.values[0]
print("Total LED up time: " + str(upTime) + " seconds");
x = upTime * 20 * 20 * 220 * 10 ** -6
energy = round(x, 2)
print("Energy cosumed by LED: " + str(energy) + " watt-second")

