#ifndef MAPBOXGLMASTER_H
#define MAPBOXGLMASTER_H

#include <QByteArray>
#include <QObject>
#include <QString>
#include <QSet>

#include <mutex>

class MapboxGLMaster : public QObject
{
  Q_OBJECT

public:
  explicit MapboxGLMaster(QObject *parent = nullptr);
  virtual ~MapboxGLMaster();

  bool getTile(int x, int y, int z, QByteArray &result, bool &compressed, bool &found);

signals:

public slots:
  void onSettingsChanged();
  void onMapboxGLChanged(QString world_database, QSet<QString> country_databases);

protected:
  std::mutex m_mutex;
  QSet<QString> m_db_connections;

  QString m_world_fname;
  QSet<QString> m_country_fnames;

  const int const_section_level{7};
  const QString const_conn_world{"mapboxgl: world"};
  const QString const_conn_prefix{"mapboxgl: "};
};

#endif // MAPBOXGLMASTER_H