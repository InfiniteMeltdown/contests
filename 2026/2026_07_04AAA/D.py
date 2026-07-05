k = int(input())

groups = {
    "STA": [],
    "PLN": [],
    "SAT": []
}

for _ in range(k):
    s = input()
    data = s.split("_")

    result = ""
    record_type = ""

    if data[0] == "STA":
        record_type = "STA"

        name = data[2].split("-")

        result = name[2] + "_"
        result += name[0] + "_"
        result += name[1] + "_"
        result += data[3] + "_"
        result += data[0] + "_"
        result += data[7] + "_"
        result += data[6].split("-")[0]

    elif data[0] == "PLN":
        record_type = "PLN"

        name = data[3].split("-")

        result = name[0] + "_"
        result += name[1] + "_"
        result += name[2] + "_"
        result += data[2] + "_"
        result += data[0] + "_"
        result += data[4] + "_"
        result += data[7].split("-")[0]

    elif len(data[0]) == 4 and data[0].isdigit():
        record_type = "SAT"

        if data[1] != "FE":
            result = data[6] + "_"
            result += data[7] + "_"
            result += data[8] + "_"
            result += data[4] + "_"
            result += data[1] + "_"
            result += data[5] + "_"
            result += data[0]

    else:
        # AST — не попадает в сводку
        result = ""

    if result != "":
        groups[record_type].append(result)

for record_type in sorted(groups):
    if len(groups[record_type]) > 0:
        print(len(groups[record_type]))

        for row in sorted(groups[record_type]):
            print(row)