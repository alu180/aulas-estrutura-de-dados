import re

def main():
    pattern = r'\b[A-Za-z]+\b'
    text = "Hello, world! This is a test."
    words = re.findall(pattern, text)
    print("Words found:", words)

if __name__ == "__main__":
    main()