# epever_exporter

epever_exporter is a standalone program written in C that can query Epever/Epsolar Tracer solar charge controllers and output metrics compatible with Prometheus.

This allows to monitor PV production, battery status, etc. on a nice Grafana interface.

## Build

```bash
apt install clang libbsd-dev libmodbus-dev
make
```

## Kudos

The "ModBus Register Address List" PDF document has been a very valuable resource. A copy of it is included in this Git repository. The original file can be downloaded at [solar-elektro.cz](http://www.solar-elektro.cz/data/dokumenty/1733_modbus_protocol.pdf). Thank you to the original author for their work.

## Other brands

Would like to monitor Growatt solar inverters instead? Here is a sister repository for that: https://github.com/infertux/growatt_exporter

## License

AGPLv3+
