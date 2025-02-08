import os
from typing import List


def get_version() -> str:
    init: str = os.path.join(os.path.dirname(__file__), "../../pyproject.toml")

    with open(init) as file:
        data: List[str] = file.readlines()

    version_line: str = next(line for line in data if line.startswith("version = "))

    version: str = version_line.split("=")[1]
    version = version.strip().replace('"', "")

    return version


if __name__ == "__main__":
    print(get_version())
