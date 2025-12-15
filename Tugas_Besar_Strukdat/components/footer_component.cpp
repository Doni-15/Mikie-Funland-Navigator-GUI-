#include "components/footer_component.h"
#include <QDate>

FooterComponent::FooterComponent(QFrame *frame, QObject *parent) : QObject(parent), m_frame(frame){
    if (m_frame) {
        setupUI();
        setupStyle();
    }
}

void FooterComponent::setupUI(){
    QVBoxLayout *layout = new QVBoxLayout(m_frame);
    layout->setContentsMargins(10, 5, 10, 5);
    layout->setSpacing(2);
    layout->setAlignment(Qt::AlignCenter);

    QString year = QString::number(QDate::currentDate().year());
    QString mainText = "© " + year + " <b>Mikie Funland Navigator</b> • Kelompok 5";

    m_lblMain = new QLabel(mainText, m_frame);
    m_lblMain->setObjectName("lblMain");
    m_lblMain->setAlignment(Qt::AlignCenter);

    QString subText = "Struktur Data USU • Implementasi Graph, Sorting & Searching";

    m_lblSub = new QLabel(subText, m_frame);
    m_lblSub->setObjectName("lblSub");
    m_lblSub->setAlignment(Qt::AlignCenter);

    layout->addWidget(m_lblMain);
    layout->addWidget(m_lblSub);
}

void FooterComponent::setupStyle(){
    QString style = R"(
        QFrame {
            background-color: rgba(207, 250, 254, 255);
        }

        QLabel#lblMain {
            color: rgba(0, 0, 0, 255);
            font-size: 15px;
            font-weight: bold;
            font-family: "Segoe UI", sans-serif;
            background-color: rgba(207, 250, 254, 255);
        }

        QLabel#lblSub {
            color: rgba(10, 10, 10, 255);
            font-size: 12px;
            font-family: "Segoe UI", sans-serif;
            margin-top: 2px;
            background-color: rgba(207, 250, 254, 255);
        }
    )";

    m_frame->setStyleSheet(style);
}
