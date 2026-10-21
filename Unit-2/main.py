"""
Case Study: Social Network Friendship Connections using an Adjacency Matrix
Language: Python
"""

def create_adjacency_matrix(users, friendships):
    """Create an undirected adjacency matrix from users and friendship pairs."""
    n = len(users)
    matrix = [[0 for _ in range(n)] for _ in range(n)]
    index = {user: i for i, user in enumerate(users)}

    for user_a, user_b in friendships:
        if user_a not in index or user_b not in index:
            print(f"Warning: ignoring unknown friendship ({user_a}, {user_b})")
            continue
        i, j = index[user_a], index[user_b]
        matrix[i][j] = 1
        matrix[j][i] = 1  # Friendship is mutual in this example.

    return matrix, index


def display_matrix(users, matrix):
    """Print the matrix with user names as row and column labels."""
    width = max(5, max(len(user) for user in users) + 1)
    print("".ljust(width), end="")
    for user in users:
        print(user[:width - 1].rjust(width), end="")
    print()

    for i, user in enumerate(users):
        print(user[:width - 1].ljust(width), end="")
        for value in matrix[i]:
            print(str(value).rjust(width), end="")
        print()


def are_friends(user_a, user_b, matrix, index):
    """Return whether two users are directly connected."""
    if user_a not in index or user_b not in index:
        return False
    return matrix[index[user_a]][index[user_b]] == 1


def list_friends(user, users, matrix, index):
    """Return all direct friends of one user."""
    if user not in index:
        return []
    row = matrix[index[user]]
    return [users[i] for i, connected in enumerate(row) if connected == 1]


def main():
    # Small sample dataset to demonstrate the idea.
    users = ["Asha", "Ravi", "Neha", "Om", "Sara"]
    friendships = [
        ("Asha", "Ravi"),
        ("Asha", "Neha"),
        ("Ravi", "Om"),
        ("Neha", "Om"),
        ("Om", "Sara"),
    ]

    matrix, index = create_adjacency_matrix(users, friendships)

    print("SOCIAL NETWORK: FRIENDSHIP ADJACENCY MATRIX")
    print("--------------------------------------------")
    print("Users:", ", ".join(users))
    print("\nAdjacency Matrix (1 = friends, 0 = not directly connected):")
    display_matrix(users, matrix)

    print("\nAre Asha and Ravi friends?",
          "Yes" if are_friends("Asha", "Ravi", matrix, index) else "No")
    print("Are Asha and Sara friends?",
          "Yes" if are_friends("Asha", "Sara", matrix, index) else "No")
    print("Direct friends of Om:", ", ".join(list_friends("Om", users, matrix, index)))


if __name__ == "__main__":
    main()
