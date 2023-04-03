import sys
import random

if len(sys.argv) < 2:
    print("Provide path to 'api' Python module.")
    exit(1)
else:
    sys.path.append(sys.argv[1])

import api

print("Python API client, starting...\n")

message = api.message()
message.type = api.message_type.RED
message.data = random.randint(0, 255)

api.send(message)
message = api.read()
