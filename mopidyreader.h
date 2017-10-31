#ifndef MOPIDYREADER_H
#define MOPIDYREADER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>


class MopidyReader : public QObject
{
    Q_OBJECT
public:
    explicit MopidyReader(QObject *parent);

    void Update();

signals:

public slots:

private:
    QNetworkAccessManager *manager;
    void ReadMopidy(QNetworkReply* reply);
};

#endif // MOPIDYREADER_H
