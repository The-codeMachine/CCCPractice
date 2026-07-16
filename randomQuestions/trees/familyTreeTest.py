import random
import subprocess
import os


def generate_tree(n):
    """
    Generates a random rooted tree.
    Node 1 is always the root.
    """

    edges = []

    for node in range(2, n + 1):
        parent = random.randint(1, node - 1)
        edges.append((parent, node))

    return edges


def solve_bruteforce(n, edges):
    """
    Correct solution.
    Used only for testing.
    """

    children = [[] for _ in range(n + 1)]

    for parent, child in edges:
        children[parent].append(child)

    def height(node):
        if not children[node]:
            return 0

        best = 0

        for child in children[node]:
            best = max(best, height(child) + 1)

        return best

    return height(1)


def run_solution(input_data):
    """
    Runs the user's program.
    """

    result = subprocess.run(
        ["a.exe"],
        input=input_data,
        text=True,
        capture_output=True
    )

    if result.returncode != 0:
        print("Program crashed!")
        print(result.stderr)
        return None

    return result.stdout.strip()


def make_input(n, edges):
    data = []

    data.append(str(n))

    for p, c in edges:
        data.append(f"{p} {c}")

    return "\n".join(data)


def main():

    tests = 100

    for test in range(1, tests + 1):

        n = random.randint(2, 100)

        edges = generate_tree(n)

        expected = solve_bruteforce(n, edges)

        input_data = make_input(n, edges)

        output = run_solution(input_data)


        if output is None:
            return


        try:
            answer = int(output)
        except:
            print("Invalid output:")
            print(output)
            return


        if answer != expected:
            print("FAILED TEST")
            print("----------------")
            print(input_data)
            print()
            print("Expected:", expected)
            print("Got:", answer)
            return


    print("All tests passed!")


if __name__ == "__main__":
    main()