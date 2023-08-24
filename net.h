struct net_device{
	struct net_device *next;
	unsigned int index;
	char name[IFNAMSIZ];
	uint16_t type;
	uint16_t mtu;
	uint16_t flags;
	uint16_t hlen; /* header length */
	uint16_t alen; /* address length */
	uint8_t addr[NET_DEVICE_ADDR_LEN];
	union{
		uint8_t peer[NET_DEVICE_ADDR_LEN];
		uint8_t broadcast[NET_DEVICE_ADDR_LEN];
	};
	struct net_device_ops * ops;
	void *priv;
};

struct net_device_ops{
	int (*open)(struct net_device *dev);
	int (*close)(struct net_device *dev);
	int (*transmit)(struct net_device *dev, uint16_t type, const uint8_t *data, size_t len, const void *dst);
};
