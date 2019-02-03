from bluetooth import *

print("performing inquiry...")

nearby_devices = discover_devices(lookup_names = True)

print("Found %d devices" % len(nearby_devices))

for name, addr in nearby_devices:
	print("%s - %s" % (addr, name))

service = find_service(address="00:06:66:f2:49:7d")

print(service)
